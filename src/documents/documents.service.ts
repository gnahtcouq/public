/* eslint-disable prefer-const */
import { BadRequestException, Injectable } from '@nestjs/common';
import { CreateDocumentDto, CreateUserDocDto } from './dto/create-document.dto';
import { UpdateDocumentDto } from './dto/update-document.dto';
import { SoftDeleteModel } from 'soft-delete-plugin-mongoose';
import {
  Document,
  DocumentDocument,
} from 'src/documents/schemas/document.schema';
import { InjectModel } from '@nestjs/mongoose';
import { IUser } from 'src/users/users.interface';
import mongoose from 'mongoose';
import aqp from 'api-query-params';

@Injectable()
export class DocumentsService {
  constructor(
    @InjectModel(Document.name)
    private documentModel: SoftDeleteModel<DocumentDocument>,
  ) {}

  async create(createUserDocDto: CreateUserDocDto, user: IUser) {
    const { name, url } = createUserDocDto;
    const { email, _id } = user;

    const newDocument = await this.documentModel.create({
      name,
      url,
      email,
      userId: _id,
      status: 'ACTIVE',
      createdBy: { _id, email },
      history: [
        {
          status: 'ACTIVE',
          updatedAt: new Date(),
          updatedBy: {
            _id: user._id,
            email: user.email,
          },
        },
      ],
    });
    return {
      _id: newDocument?._id,
      createdAt: newDocument?.createdAt,
    };
  }

  async findAll(currentPage: number, limit: number, qs: string) {
    const { filter, sort, population, projection } = aqp(qs);
    delete filter.current;
    delete filter.pageSize;

    let offset = (+currentPage - 1) * +limit;
    let defaultLimit = +limit ? +limit : 10;

    const totalItems = (await this.documentModel.find(filter)).length;
    const totalPages = Math.ceil(totalItems / defaultLimit);

    const result = await this.documentModel
      .find(filter)
      .skip(offset)
      .limit(defaultLimit)
      .sort(sort as any)
      .populate(population)
      .select(projection as any)
      .exec();

    return {
      meta: {
        current: currentPage, //trang hiện tại
        pageSize: limit, //số lượng bản ghi đã lấy
        pages: totalPages, //tổng số trang với điều kiện query
        total: totalItems, //tổng số phần tử (số bản ghi)
      },
      result, //kết quả query
    };
  }

  async findOne(id: string) {
    if (!mongoose.Types.ObjectId.isValid(id)) {
      throw new BadRequestException('ID không hợp lệ!');
    }
    return await this.documentModel.findById(id);
  }

  async findByUsers(user: IUser) {
    return await this.documentModel
      .find({ userId: user._id })
      .sort('-createdAt');
  }

  async update(_id: string, status: string, user: IUser) {
    if (!mongoose.Types.ObjectId.isValid(_id)) {
      throw new BadRequestException('ID không hợp lệ!');
    }
    const updated = await this.documentModel.updateOne(
      { _id },
      {
        status,
        updatedBy: {
          _id: user._id,
          email: user.email,
        },
        $push: {
          history: {
            status,
            updatedAt: new Date(),
            updatedBy: {
              _id: user._id,
              email: user.email,
            },
          },
        },
      },
    );
    return updated;
  }

  async remove(id: string, user: IUser) {
    await this.documentModel.updateOne(
      { _id: id },
      {
        deletedBy: {
          _id: user._id,
          email: user.email,
        },
      },
    );
    return this.documentModel.softDelete({
      _id: id,
    });
  }
}

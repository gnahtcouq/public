@echo off
echo ++++++++++++++++++++++++++++++++++++
echo Ho ten: Tran Van Quoc Thang
echo MSSV: DH52007101
echo Lop: D20_TH11
echo ++++++++++++++++++++++++++++++++++++

E:
md "MSSV CUA BAN"
cd "MSSV CUA BAN"
md "THUC HANH"
cd "THUC HANH"
md "CUOI KY"
md "GIUA KY"
cd "CUOI KY"
md LINUX
cd LINUX
md COMMAND
md GRAPHIC
cd GRAPHIC
md ICON
cd ..
cd ..
cd ..
cd "GIUA KY"
md "BATCH FILE"
md COMMAND
cd ..
cd ..
cd ..

echo.
:start
echo "Chon T: Hien thi cay thu muc"
echo "Chon V: Hien thi phien ban he dieu hanh DOS"
echo "Chon C: Xoa man hinh"
echo "Chon E: Ket thuc"
choice /c TVCE /m "Hay chon: "
if %errorlevel%==1 goto nhan1
if %errorlevel%==2 goto nhan2
if %errorlevel%==3 goto nhan3
if %errorlevel%==4 goto nhan4
:nhan1
tree "MSSV CUA BAN"
goto start
:nhan2
ver
goto start
:nhan3
cls
goto start
:nhan4

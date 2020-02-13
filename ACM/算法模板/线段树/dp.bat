:start
data >in
test <in >out1
std <in >out2
fc out1 out2
if errorlevel 1 pause
goto start

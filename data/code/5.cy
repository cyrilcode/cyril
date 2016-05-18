move 0,0,4
rotate 45,1,0,0
scale 2
color red,200
push
do 4 times
rotate FRAME / 8, 0,1,0
push
rotate FRAME / 10,0,1,0
tile 4,4,4
 box 0.25,0.025,0.01
end
pop
end
pop
color lightBlue,50
push
move 0,0,-1
do 1 times
rotate 0 - FRAME / 20,0,1,0
push
rotate FRAME / 6,0,1,0
tile 4,4,4
ball 0.1,0.2,0.15
end
pop

end
pop

fxNW
//fxNW wave(12300)*20,fft(10)/10,wave(12200)
//fxK KICK

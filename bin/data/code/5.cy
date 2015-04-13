move 0,0,4
rotate 45,1,0,0
scale 2
color white
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

push
move 0,0,-1
do 10 times
rotate 0 - FRAME / 20,0,1,0
push
rotate FRAME / 6,0,1,0
tile 4,4,4
box 0.1,0.02,0.05
end
pop

end
pop

fxB 3

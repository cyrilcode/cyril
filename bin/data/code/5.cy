background 0,0,0,0
color white
//fill
stroke 3

i: i + 0.05
if KICK
 j: 2
end
j: j - 0.09
tile 15,8
shape 
 x: sin(i)
 y: cos(i)
 rotate wave(1000) * 360,1,1,0
 vert 0 - j,0 - j
 vert x,0
 vert 0,y
 vert j,j
end
end




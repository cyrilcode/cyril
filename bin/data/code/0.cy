

rotate

a: a + 0.01
b: b + 0.01
c: c + 0.01

i: noise(a) * 0.1
j: noise(1,b) * 0.05
k: noise(1,1,c) * 0.05

do 2 times
do 4 times
rotate 90
particle 0, i,j,k
 color white,(1 - HEALTH) * 255
 if HEALTH < 0.7 box HEALTH
end
end
i: 0 - i
j: 0 - j
k: 0 - k
end

//fxK 1 
//fxNW

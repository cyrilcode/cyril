background 0,0,0,0
color white
fill

i: 0
x: -8
move -8,0
do 32 times
 move 0.25,0
 rect 0.25, fft(i) * 4 
 i: i + 1
end

do 32 times
 move 0.25,0
 rect 0.25, fft(i) * 4 
 i: i - 1
end





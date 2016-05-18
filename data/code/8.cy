fill
palette $p
// 10 red
 10 yellow
 10 orange
end
scale 10
rotate 90,1,0,0
stroke 2
i: 0
do 10 times
i: i + 0.1
color lerp($p, i)
color pink
rotate FRAME / 100, 0,1,0
cone
end

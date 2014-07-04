scale 3
i: i + 0.1
tile 3,3
 rotate FRAME
 particle noise(i) * 0.5
  color HEALTH * 255
  box 0.25
 end
end

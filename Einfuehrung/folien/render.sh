pandoc -t revealjs -s folien.markdown -o folien.html \
  --template=revealjs-template.html --slide-level=1 \
  -V theme=night -V center=false -V transition=none \
  -V slideNumber=true \
  -V width=1024 -V height=768

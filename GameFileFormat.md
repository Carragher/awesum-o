# Game File Format #

Each line of the file corresponds to an object that will be loaded into the model.

# Details #

## Tiles ##
```
<id> <x> <y> <parent type> <image> <child type>
```

## Enemies ##
```
<id> <x> <y> <parent type> <image> <child type>
```

## Bullets ##
```
<id> <x> <y> <parent type> <image> <child type> <target id>
```

# Example File #
```
:::TILES:::
20 50 50 tile :/images/tower.jpg tower
23 100 250 tile :/images/path.jpg path
25 350 50 tile :/images/grass.jpg normal

:::ENEMIES:::
5 0 0 enemy :/images/walker.jpg walker
8 100 150 enemy :/images/yolo.jpg YOLO

:::BULLETS:::
9 250 100 bullet :/images/bullet.jpg 8 
```
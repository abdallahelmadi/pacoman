## 👾 pacoman

`pacoman` is a project where I create a simple 2D game using **MiniLibX** of 42network.
The player moves inside a map, collects all collectibles, and then escapes through the exit.

---

## 🗺️ Map Requirements

The game map is defined in a `anypath/anyname.ber` file.
It must respect the following rules:

- **Rectangular**: All rows must have the same length.
- **Surrounded by walls**: The map must be closed/surrounded by `1`.
- **Allowed characters**:
  - `1` → Wall  
  - `0` → Free space  
  - `C` → Collectible  
  - `E` → Exit  
  - `P` → Player starting position
- **Required elements**:
  - At least **1 exit** (`E`)
  - At least **1 collectible** (`C`)
  - Exactly **1 player** (`P`)
- **No invalid characters** are allowed.

---

## ✅ Valid Map Example
11111111111<br/>
1000000C001<br/>
1P1111111E1<br/>
10C0X000C01<br/>
11111111111<br/>

## 🎮 Controls
- **W / ↑** → Move up
- **S / ↓** → Move down
- **A / ←** → Move left
- **D / →** → Move right
- **ESC** → Close the game

## 🚀 How to Run

#### Fisrt you need to install dependencies by run this file:
```
./installdependencies
```
May take some seconds, sudo will ask you for sudopassword

#### Example to strat play:
```
./pacoman maps/0.ber
```
Choose the map you want, or create yours in /map folder or any other path.

---

<video autoplay loop muted playsinline width="600">
  <source src="./video.webm" type="video/mp4">
</video>
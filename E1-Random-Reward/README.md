# 实验一 · 奖励随机组（Loot Box 抽卡实验程序）
# Study 1 · Random-Reward Condition (Loot Box experiment program)

[← 返回仓库首页 / Back to repository root](../README.md)

| 项目 Item | 内容 |
|---|---|
| 实验 Study | 实验一（好奇动机 curiosity motivation） |
| 条件 Condition | 抽奖结果奖励**随机** / reward **random** |
| 自变量 IV | 抽卡奖励（奖励固定 / 奖励随机） |
| 因变量 DV | 抽奖次数、游戏时长、通过管道总数 |
| 中文组名 | 实验一 · 奖励随机组 |
| Qt 模块 | `core` `gui` `widgets` `multimedia` |

---

## 简体中文

### 这个程序是什么

本工程是论文实验一中「**奖励随机组**」的完整实验程序：被试玩 Flappy Bird 赚取抽奖机会，
在商店抽卡，**每次抽到的都是不同样式的小熊**（奖池中 84 张图片内容各不相同），
以此制造抽奖结果的不确定性、诱发好奇动机。指导语中对该组的描述为：

> 奖池内包含**不同样式**的小熊图片，每次抽奖结果会呈现在上方的方框中，
> 抽取方式为有放回抽取，会抽到重复的图片。

### 组别关键设置（与固定组的唯一实质差异）

| 位置 | 内容 |
|---|---|
| `Images/A1.png … A84.png` | **84 张图片内容各不相同**（84 个不同 SHA-256），每次抽到的样式都不同 |
| `shuoming.ui` | 奖池说明文案为"奖池内包含不同样式的小熊图片…会抽到重复的图片" |
| `choujiang.cpp` | 抽奖按钮未启用 3.5 秒防连点计时器 |

### 编译与运行

```bash
# 用 Qt Creator 直接打开 FlappyBird.pro，或：
qmake FlappyBird.pro
make            # Windows + MinGW 使用 mingw32-make
```

环境：Qt 5.12+（原始实验为 Qt 5.15.2 / MinGW 8.1 32-bit / Windows），需要 `multimedia` 模块。

### 实验流程

1. 主试分配被试编号 → 打开本程序；
2. 被试在开始界面输入编号；
3. 阅读指导语 → 开始游戏；
4. 每通过 **3 个管道**获得 **1 次**抽奖机会；
5. 在商店抽奖（有放回抽取，每次概率相同），每次结果出现后弹出 1–7 点"想要"评分框；
6. 被试自行决定结束时机 → 程序把 `TOTALSCORE`、`CJNUM` 追加写入 `testee.txt`。

### 数据输出

```text
TOTALSCORE:12,  CJNUM:9
```

字段含义与解析示例见 [../docs/DATA_FORMAT.md](../docs/DATA_FORMAT.md)。

### 目录结构

```text
E1-Random-Reward/
├── FlappyBird.pro          # qmake 工程
├── main.cpp                # 程序入口
├── mainwindow.*            # 游戏主窗口（改造自上游 Flappy Bird）
├── formmenu.*              # 被试编号录入 / 开始界面
├── forminstruction.*       # 指导语
├── choujiang.*             # 抽奖核心逻辑      ← 组别差异点
├── shuoming.*              # 奖池说明页        ← 组别差异点
├── pingfen.*               # 1–7 点"想要"评分框
├── Module/                 # bird / ground / pipe / scoreboard / fbnumLCD / redyboard
├── Images/  sounds/        # 资源（84 张普通小熊图在本组各不相同）
├── flappy.qrc              # Qt 资源清单
└── testee.txt              # 行为数据输出（结束后追加）
```

### 注意事项

- 若运行时报缺少 `Qt5Core.dll` / `Qt5Multimedia.dll`，请把 `Qt/5.15.x/mingw81_32/bin` 加入 `PATH`，
  或执行 `windeployqt FlappyBird.exe`；
- 数据文件写在**程序当前工作目录**，建议为每名被试单独建目录运行。

### 演示 Demo

<img src="../docs/demo/E1-Random-Reward.gif" alt="实验一 · 奖励随机组 操作演示" width="620">

---

## English

### What this program is

This project is the complete implementation of the **Random-Reward** condition of Study 1:
participants play Flappy Bird to earn draws, then draw cards in the shop and **every draw returns a
different bear** — the 84 images in the pool are all distinct. This creates outcome uncertainty and is
intended to induce curiosity motivation. The on-screen description reads:

> 奖池内包含**不同样式**的小熊图片…抽取方式为有放回抽取，会抽到重复的图片。
> ("The pool contains bears of *different styles*; sampling is with replacement, so repeats can occur.")

### Key condition settings (the only substantive difference from the Fixed group)

| Location | Content |
|---|---|
| `Images/A1.png … A84.png` | **all 84 files are distinct** (84 different SHA-256 hashes) |
| `shuoming.ui` | pool text: "bears of different styles … sampling with replacement" |
| `choujiang.cpp` | the **3.5 s draw-button debounce** is not enabled here |

### Build and run

```bash
# open FlappyBird.pro in Qt Creator, or:
qmake FlappyBird.pro
make            # mingw32-make on Windows + MinGW
```

Requirements: Qt 5.12+ (the original study used Qt 5.15.2 / MinGW 8.1 32-bit / Windows) with the `multimedia` module.

### Procedure

1. The experimenter assigns a participant ID and launches this program.
2. The participant enters the ID on the start screen.
3. Instructions are shown, then the game starts.
4. Every **3 pipes passed** grants **1 draw credit**.
5. Draw in the shop (with replacement, equal probability each time); a 1–7 "wanting" dialog follows each draw.
6. The participant ends the session whenever they like — `TOTALSCORE` and `CJNUM` are appended to `testee.txt`.

### Data output

```text
TOTALSCORE:12,  CJNUM:9
```

See [../docs/DATA_FORMAT.md](../docs/DATA_FORMAT.md) for field meanings and a parsing example.

### Demo

<img src="../docs/demo/E1-Random-Reward.gif" alt="Study 1 random-reward condition walkthrough" width="620">

### Notes

- If `Qt5Core.dll` / `Qt5Multimedia.dll` is missing, add `Qt/5.15.x/mingw81_32/bin` to `PATH` or run `windeployqt FlappyBird.exe`.
- `testee.txt` is written to the program's **current working directory**; run each participant in a separate folder.

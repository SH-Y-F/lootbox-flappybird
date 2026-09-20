# 论文实验条件 ↔ 四个程序 的映射依据
# Mapping: thesis conditions ↔ the four programs

本文件说明 `E1-Fixed-Reward`、`E1-Random-Reward`、`E2-Low-Value-Rare`、`E2-High-Value-Rare`
四个目录是如何与论文中的四个实验条件一一对应上的，以及每条结论的**可复核证据**。

This document records how the four folders were matched to the four thesis conditions,
together with the reproducible evidence for each claim.

---

## 1. 论文描述的四个条件 · The four conditions as described in the thesis

> "实验一总共有两个程序，每个程序中像素小鸟游戏相同，区别在于不同的抽奖系统，具体而言，奖励物品固定组每次只会抽到同样的物品（相同的小熊图片），而奖励物品随机组每次抽到的物品不同（不同样式的小熊图片），与抽取方式为有放回抽取。"
>
> "实验二总共有两个程序，每个程序游戏相同，但抽奖系统不同，具体而言为实验二的抽奖系统的卡池中只会出现两种卡，一种为普通卡（即普通小熊），另一种为稀有卡（即带金色边框的小熊）。稀有奖励相对低组（低价值组）每抽到一次稀有卡，会在原本基础被试费上额外增加 0.5 元，而稀有奖励相对高组（高价值组）则是每抽到一次稀有卡，都会在原本基础被试费上额外增加 3 元。"

| # | 实验 Study | 条件 Condition | 操作定义 Operationalisation |
|---|---|---|---|
| 1 | 实验一 | 奖励固定 Fixed | 每次抽到同一只小熊（奖池图片相同） |
| 2 | 实验一 | 奖励随机 Random | 每次抽到不同样式的小熊（奖池图片不同） |
| 3 | 实验二 | 稀有价值相对低 Low | 稀有卡（金色边框）每张 +0.5 元 |
| 4 | 实验二 | 稀有价值相对高 High | 稀有卡（金色边框）每张 +3 元 |

---

## 2. 证据链 · Evidence chain

### 2.1 奖池图片内容 · Draw-pool image contents

对每个工程 `Images/A*.png`（84 个文件）逐一计算 SHA-256：

| 目录 Folder | 不同的 A 图数量 distinct images | 结论 Conclusion |
|---|---|---|
| `E1-Fixed-Reward` | **1 / 84**（84 个文件字节完全相同） | 抽奖结果恒定 → 奖励固定组 |
| `E1-Random-Reward` | **84 / 84**（每个文件都不同） | 每次抽到不同样式 → 奖励随机组 |
| `E2-Low-Value-Rare` | 1 / 84（+ 3 张稀有卡 `S1/S3/S4.png`） | 普通卡 + 稀有卡奖池 |
| `E2-High-Value-Rare` | 1 / 84（+ 3 张稀有卡 `S1/S3/S4.png`） | 普通卡 + 稀有卡奖池 |

复核命令 / verify:

```powershell
Get-ChildItem .\E1-Fixed-Reward\Images\A*.png |
  ForEach-Object { (Get-FileHash $_.FullName).Hash } |
  Sort-Object -Unique | Measure-Object
```

### 2.2 奖池说明文案 · Pool description text

`shuoming.ui` 中 `textBrowser` 的 HTML 文案：

| 目录 Folder | 文案原文 |
|---|---|
| `E1-Fixed-Reward` | 奖池内有**相同**的小熊图片 / 每次抽奖结果会呈现在上方的方框中 |
| `E1-Random-Reward` | 奖池内包含**不同样式**的小熊图片 / …抽取方式为有放回抽取，会抽到重复的图片 |
| `E2-Low-Value-Rare` | 奖池内包含普通奖和神秘大奖…神秘大奖抽中可获得 **0.5元现金** |
| `E2-High-Value-Rare` | 奖池内包含普通奖和神秘大奖…神秘大奖抽中可获得 **三元现金** |

### 2.3 抽奖代码 · Draw logic

`E2-*` 的 `choujiang.cpp` 相比 `E1-*` 增加了稀有条目与稀有卡判定：

```cpp
const QStringList imageList = { /* … ":/Images/S1.png", ":/Images/S3.png", ":/Images/S4.png" … */ };

int index = QRandomGenerator::global()->bounded(imageList.count());
if (XXX > 2) index = 1;                       // 稀有卡数量上限保护
if (imageList.at(index) == ":/Images/S1.png") { XXX++; emit emit_pingfen1(); }
else if (imageList.at(index) == ":/Images/S3.png") { XXX++; emit emit_pingfen2(); }
else if (imageList.at(index) == ":/Images/S4.png") { XXX++; emit emit_pingfen3(); }
// …普通卡只触发 emit_pingfen4..10（评分），不累计 XXX
```

`XXX` 仅在抽到稀有卡时自增 → 稀有卡计数；抽到稀有卡与普通卡都会弹出评分框。

### 2.4 仅一处差异 · Single-point difference within Study 2

对 `E2-Low-Value-Rare` 与 `E2-High-Value-Rare` 全目录逐文件比对：

```text
DIFF: shuoming.ui      （唯一差异文件 / the only differing file）
```

这与论文"两个程序游戏相同，但抽奖系统不同（仅稀有奖励价值不同）"的表述一致。

### 2.5 组别脚本对应关系 · Which file served which group

原始实验机上的四个运行目录只保留了**生成物**（`ui_*.h`、`Makefile`、`testee.txt` 等），源码已不在其中。对应关系由生成物反推：

| 运行目录 | `ui_shuoming.h` 中的关键文案 | 映射到 / mapped to |
|---|---|---|
| `1` | 奖池内有相同的小熊图片 | `E1-Fixed-Reward` |
| `2` | 奖池内包含不同样式的小熊图片 | `E1-Random-Reward` |
| `3` | 神秘大奖抽中可获得 0.5元现金 | `E2-Low-Value-Rare` |
| `4` | 神秘大奖抽中可获得 三元现金 | `E2-High-Value-Rare` |

---

## 3. 需要注意的复现事项 · Reproducibility caveats

1. **`E2-High-Value-Rare/shuoming.ui` 是重建文件。** 高价值组的 `.ui` 源文件在原始资料中缺失，
   本仓库依据该组程序运行时生成的 `ui_shuoming.h`（Qt 5.15.2 uic 产物）**逐字还原**，
   且除 `textBrowser` 的 HTML 文案外与低价值组保持完全一致。该文件可以用 Qt Designer 正常打开与编辑。
   *The High-Value `.ui` was lost and has been reconstructed verbatim from that build's generated `ui_shuoming.h`;
   apart from the `textBrowser` HTML it is byte-identical to the Low-Value file.*
2. **`E1-Fixed-Reward` 的 84 张图片是同一文件的副本**，仓库中如实保留（约 4.8 MB）。
   若你只想复现逻辑，可以把 `Images/A*.png` 换成单一图片并缩短 `imageList`。
3. 三个来源工程在原始目录中分别为 `QtFlappyBird-master - 2.1__1`、`2.1__2`、`2.1__34`
   （见 [MODIFICATIONS.md](MODIFICATIONS.md)）。

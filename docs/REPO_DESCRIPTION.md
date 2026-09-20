# 仓库描述文案 · Repository description kit

用于 GitHub 仓库的 **About 栏（Description）**、**Topics（话题标签）** 与 **官网/发布栏**。

---

## 1. 推荐直接用这一条（Description · 中英混排）

> **GitHub About 栏字符上限 350，建议控制在 120–200 字符。**

```text
Loot Box 抽卡行为实验程序（Qt 5 / C++）。Flappy Bird + 开箱任务，四个实验条件：奖励固定 / 奖励随机 / 稀有价值低（0.5元）/ 稀有价值高（3元）。Four Qt implementations of a Flappy Bird + loot-box task.
```

字符数：**150** ✅（按 Unicode 字符计，GitHub 上限 350）

**备选 A —— 纯中文（76 字符）**

```text
基于 Qt 5 的 Flappy Bird 抽卡（Loot Box）行为实验程序，含奖励固定／奖励随机／稀有价值高低共四个实验条件的完整源码与编译说明。
```

**备选 B —— 纯英文（197 字符）**

```text
Four Qt 5 (C++) programs for a Flappy Bird + loot-box behavioural task. Study 1: fixed vs random draw reward. Study 2: rare-reward value CNY 0.5 vs CNY 3. Full sources, build guide and data format.
```

**备选 C —— 极简版（一句话，适合配合 Topics 使用，89 字符）**

```text
Loot Box 抽卡行为实验程序集 · Flappy Bird + gacha task in Qt 5 (C++), four experimental conditions
```

---

## 2. Topics（话题标签）

GitHub 的 Topics 只允许 **小写字母、数字、连字符**，单个不超过 50 字符，**最多 20 个**。
建议直接复制下面这一行（共 **20 个**）：

```text
qt qt5 qt-creator cpp flappy-bird loot-box gacha psychology-experiment behavioral-experiment experimental-psychology research-software game-motivation curiosity wanting reinforcement-learning-schedule qmake gui-application reproducible-research thesis open-science
```

**每个标签的用意**

| # | Topic | 说明 |
|---|---|---|
| 1 | `qt` `qt5` `qt-creator` | 主要技术栈与 IDE，Qt 用户会按此检索 |
| 2 | `cpp` | 语言 |
| 3 | `flappy-bird` | 任务范式，最容易被人搜到 |
| 4 | `loot-box` `gacha` | 核心研究主题（英文 / 日式说法都覆盖） |
| 5 | `psychology-experiment` `behavioral-experiment` `experimental-psychology` | 学科归属，方便同行检索 |
| 6 | `research-software` `reproducible-research` `open-science` | 标明这是科研工具而非游戏，且可复现 |
| 7 | `game-motivation` `curiosity` `wanting` | 论文的两个核心动机变量 |
| 8 | `reinforcement-learning-schedule` | 随机奖励机制的理论背景（可变比率强化） |
| 9 | `qmake` `gui-application` | 构建方式与程序类型 |
| 10 | `thesis` | 来源是学位论文 |

> 如果 20 个嫌多，**优先级排序**：`qt` `loot-box` `gacha` `flappy-bird` `psychology-experiment` `research-software` `cpp` `reproducible-research`。

---

## 3. 用命令行一次设置好（推荐）

本机未安装 `git` / `gh`，需要在**已安装 GitHub CLI 并登录**的机器上执行：

```bash
gh repo edit <你的账号>/lootbox-flappybird \
  --description "Loot Box 抽卡行为实验程序（Qt 5 / C++）。Flappy Bird + 开箱任务，四个实验条件：奖励固定 / 奖励随机 / 稀有价值低（0.5元）/ 稀有价值高（3元）。Four Qt implementations of a Flappy Bird + loot-box task." \
  --add-topic qt,qt5,qt-creator,cpp,flappy-bird,loot-box,gacha,psychology-experiment,behavioral-experiment,experimental-psychology,research-software,game-motivation,curiosity,wanting,reinforcement-learning-schedule,qmake,gui-application,reproducible-research,thesis,open-science \
  --homepage "https://github.com/<你的账号>/lootbox-flappybird"
```

或在网页端：仓库首页右上角 **⚙ About** → 填 *Description* → *Topics* 逐个添加 → *Save changes*。

---

## 4. 可选的"扩展描述"（README 顶部一句话，或 Release 说明）

GitHub 的 About 栏放不下细节，可以把它放在 README 的引言块里（**当前 README 已经用了类似的引言**）：

```text
四个 Qt 5 实验程序，把经典游戏《像素小鸟》与一个抽卡/开箱系统结合起来，用于研究
Loot Box 游戏中好奇动机与想要动机对游戏行为（抽奖次数、通过管道总数、游戏时长）的影响。
每个程序都是可独立编译的完整工程，并附有编译说明、数据格式说明与组间差异清单。
```

---

## 5. 发布 Release 时的标题与说明模板

**Tag**：`v1.0.0`　**Release title**：

```text
v1.0.0 — 四个实验条件的完整源码 / Full source of the four conditions
```

**Release notes**：

```markdown
首个公开版本，包含论文所用的四个 Qt 实验程序的完整源码（仅源码，不含编译产物）。

**包含内容**
- `E1-Fixed-Reward` 实验一 · 奖励固定组（奖池 84 张图片完全相同）
- `E1-Random-Reward` 实验一 · 奖励随机组（奖池 84 张图片各不相同）
- `E2-Low-Value-Rare` 实验二 · 稀有价值相对低组（稀有卡 +0.5 元）
- `E2-High-Value-Rare` 实验二 · 稀有价值相对高组（稀有卡 +3 元）
- 中英双语 README、编译说明、数据格式说明、组间差异清单、主试操作指南

**环境**：Qt 5.12+（原始实验使用 Qt 5.15.2 / MinGW 8.1 32-bit / Windows）

**注意**
- `E2-High-Value-Rare/shuoming.ui` 为依据该组编译产物逐字重建的文件，详见 `docs/EXPERIMENT_MAPPING.md`
- 仓库不含被试数据；`testee.txt` 均为空占位文件

**First public release** — complete sources of the four Qt programs used in the study
(no build artifacts). Bilingual documentation included.
```

---

## 6. 检查清单

- [ ] About 的 Description 已填（≤ 350 字符，建议用第 1 节的推荐文案）
- [ ] Topics 已添加（建议 8 个以上，用第 2 节的列表）
- [ ] `CITATION.cff` 里的 `repository-code` 已改成真实仓库地址
- [ ] README 顶部的徽章链接正常（`LICENSE` 相对链接可点）
- [ ] 若录好了演示，`docs/demo/` 四个 GIF 已替换
- [ ] 仓库设置为 Public 前，最后确认 `testee.txt` 内没有任何真实被试数据

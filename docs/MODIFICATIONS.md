# 与上游工程的差异说明 · Differences vs. the upstream project

本仓库的四个工程均源自同一个 Qt 版 Flappy Bird 教学项目
（`QtFlappyBird-master`，其原始 README 仅含一行"Qt编写的 FlappyBird"），
并在此基础上被改造为抽卡（Loot Box）行为实验程序。

All four projects derive from the same Qt Flappy Bird teaching project
(`QtFlappyBird-master`) and were extended into a loot-box behavioural task.

---

## 1. 来源工程对应关系 · Source → repository mapping

| 仓库目录 Repo folder | 原始工程 Source project | 组别 Group |
|---|---|---|
| `E1-Fixed-Reward` | `QtFlappyBird-master - 2.1__1` | 实验一 · 奖励固定组 |
| `E1-Random-Reward` | `QtFlappyBird-master - 2.1__2` | 实验一 · 奖励随机组 |
| `E2-Low-Value-Rare` | `QtFlappyBird-master - 2.1__34` | 实验二 · 稀有价值相对低组 |
| `E2-High-Value-Rare` | `QtFlappyBird-master - 2.1__34`（仅替换 `shuoming.ui`） | 实验二 · 稀有价值相对高组 |

---

## 2. 相对上游 Flappy Bird 的改造 · Changes on top of upstream Flappy Bird

四个工程共同包含以下改造（均先于本仓库存在，本仓库未改动实验逻辑）：

| 模块 Module | 说明 Description |
|---|---|
| `choujiang.*`（新增） | 抽奖 / 开箱界面与逻辑：奖池、随机抽取、开箱动画、抽奖次数计数、数据落盘 |
| `shuoming.*`（新增） | 奖池与抽取规则说明页（组间文案不同） |
| `pingfen.*`（新增） | 抽奖后 1–7 点"想要"程度评分框（`emit_pingfen1..10`） |
| `formmenu.*`（新增） | 实验开始界面：被试编号录入 + 开始游戏 / 指导语入口 |
| `forminstruction.*`（新增） | 指导语页（说明"每通过 3 个管道获得一次抽奖机会"） |
| `mainwindow.*`（改造） | 在原游戏循环中接入抽奖入口与计分（`QPos::Fscore` / `QPos::Fcoin`） |
| `Images/`、`flappy.qrc`（改造） | 加入 84 张普通小熊图片、金色边框稀有卡、开箱动图等资源 |
| `testee.txt`（运行期产物） | 被试结束时追加一行行为数据 |

启动流程：`main.cpp` → `Formmenu`（输入编号）→ `Forminstruction`（指导语）→
`mainwindow`（Flappy Bird 游戏）→ `choujiang`（商店抽奖）→ `pingfen`（评分）→ 写 `testee.txt` 后退出。

---

## 3. 奖池素材实测结果 · Measured draw-pool assets

对每个工程 `Images/A1.png … A84.png` 逐文件计算 SHA-256 并按内容分组：

| 工程 Project | A 图不同内容数 distinct A contents | S 图（金色边框） | 说明 |
|---|---|---|---|
| `E1-Fixed-Reward` | **1 / 84**（84 个文件完全相同的同一只小熊） | 5 个文件存在但**未被代码引用** | 抽奖结果恒定 → 奖励固定 |
| `E1-Random-Reward` | **84 / 84**（每个文件内容都不同） | 5 个文件存在但**未被代码引用** | 每次抽到不同样式 → 奖励随机 |
| `E2-Low-Value-Rare` | **1 / 84** | `S1…S5.png` **5 个文件内容完全相同**，且与普通小熊不同 | 普通卡恒定 + 稀有卡 |
| `E2-High-Value-Rare` | 1 / 84 | 同 `E2-Low-Value-Rare` | 同左 |

`choujiang.cpp` 中实际被引用的图片数量：`E1-*` 为 **84** 张（`A1…A84`，不含任何 `S`），
`E2-*` 为 **94** 项（`A1…A84` 中的 81 张 + 3 张稀有卡各出现两次）。

> ⚠️ **素材层待清理（不影响复现）**：
> 1. `E1-*` 两组保留的 `Images/S1…S5.png`（金色边框小熊）**从未被 `E1` 的代码引用**，
>    属于实验二遗留资源；如需精简仓库可删除，但保留不影响编译与运行。
> 2. `E1-Random-Reward/Images/S2.png` 的**扩展名与实际编码不符**（文件名为 `.png`，内容不是 PNG）。
>    由于该文件在代码中未被引用，运行不受影响，但部分图片工具会报错。
>    本仓库为**保持实验素材原貌未做转码**，建议作者确认后决定是否修复或删除。
>
> *Asset-level caveats (do not affect reproducibility): the `S*.png` files shipped with the E1 builds are
> never referenced by E1 code, and `E1-Random-Reward/Images/S2.png` has a mismatched extension/encoding.
> Both were left untouched to preserve the original study materials.*

---

## 4. 组间差异清单 · Condition-by-condition differences

以下为脚本逐文件 SHA-256 比对的实测结果。

### 4.1 `E1-Fixed-Reward` ↔ `E1-Random-Reward`

| 变化 Change | 实测内容 |
|---|---|
| `Images/A*.png` | **83 个文件内容不同**（固定组 84 张内容完全相同；随机组 84 张各不相同） |
| `shuoming.ui` | 文案："奖池内有**相同**的小熊图片" ↔ "奖池内包含**不同样式**的小熊图片…会抽到重复的图片" |
| `choujiang.cpp` | 唯一差异是**抽奖按钮防连点计时器**：固定组保留<br>`ui->startCJ->setEnabled(false); QTimer::singleShot(3500, …);`<br>随机组这三行被注释掉 |

> ⚠️ **提交前请作者确认**：随机组的 3.5 秒防连点计时器被注释掉，属于源码层面的行为差异
> （可能导致随机组被试连点抽奖）。本仓库按原样保留，未做"统一"。
> *Before publishing, please confirm whether commenting out the 3.5 s debounce in the Random group was intentional.*

### 4.2 `E1-Fixed-Reward` ↔ `E2-Low-Value-Rare`

| 变化 Change | 实测内容 |
|---|---|
| `Images/` | **4 个文件内容不同**：`A36/A60/A84.png` 被金色边框稀有卡替换，`A16.png` 被普通小熊替换 |
| `flappy.qrc` | 资源清单变动：新增 `Images/S2.png`、`Images/S5.png`，移除 `Images/A84.png`（E1：121 项；E2：122 项） |
| `choujiang.cpp` | 奖池新增 3 张稀有卡 `S1/S3/S4.png`；新增 `int XXX = 0;` 稀有卡计数；新增 `if(XXX>2) index = 1;` 上限保护；按卡片类型分派 `emit_pingfen1..3`（稀有）/ `emit_pingfen4..10`（普通）；防连点计时器被注释 |
| `shuoming.ui` | 文案改为"奖池内包含**普通奖**和**神秘大奖**…神秘大奖抽中可获得 **0.5元现金**"，并新增普通奖 / 神秘大奖示例按钮 |

### 4.3 `E2-Low-Value-Rare` ↔ `E2-High-Value-Rare`

| 变化 Change | 实测内容 |
|---|---|
| `shuoming.ui` | **唯一差异文件**：稀有奖励文案 `0.5元现金` ↔ `三元现金` |

其余全部文件（含 `choujiang.cpp`、全部图片、`flappy.qrc`）逐字节相同。

> `E2-High-Value-Rare/shuoming.ui` 为**重建文件**：该组的 `.ui` 源文件在原始资料中缺失，
> 本仓库依据该组程序生成的 `ui_shuoming.h`（Qt 5.15.2 uic 产物）逐字还原，
> 除 `textBrowser` 的 HTML 文案外与低价值组完全一致。
> 详见 [EXPERIMENT_MAPPING.md](EXPERIMENT_MAPPING.md)。

---

## 5. 为适配 Git 仓库所做的整理 · Housekeeping changes made for this repository

| 操作 Action | 对象 Target | 原因 Reason |
|---|---|---|
| **未纳入** | `*.pro.user`、`*.pro.user.*`、`.qtc_clangd/`、`.qmake.stash` | Qt Creator / clangd 本机缓存，含原开发者机器的绝对路径 |
| **未纳入** | `Makefile`、`Makefile.Debug/Release`、`object_script.*` | qmake 生成物，平台相关 |
| **未纳入** | `ui_*.h`、`moc_*.cpp`、`qrc_*.cpp`、`*.o`、`debug/`、`release/` | 构建生成物，由 `uic`/`moc`/`rcc` 重新生成 |
| **移除** | 各工程内旧的 `README.md`（内容仅一行"Qt编写的 FlappyBird"）与旧 `.gitignore` | 由本仓库统一的中英双语 README 与根级 `.gitignore` 取代 |
| **清空** | 各工程的 `output.txt` | 原文件为空，保留占位 |
| **新增** | 根 `README.md`、`LICENSE`、`CITATION.cff`、`docs/`、四个组别 README | 便于发布与引用 |
| **新增** | `docs/demo/*.gif`（4 个占位动图） | 为 README 预留演示位；替换为真实录屏后即可发布 |

原始工程中的 `.pro.user` 等文件**并未删除**，仍保留在作者本机的源码目录（`D:\C++\1\1.2\`）中，
如需还原可按上表从对应来源工程重新复制。

### 原始运行目录对照 · What the original build folders contain

原始实验机上的四个运行目录（`1`、`2`、`3`、`4`，顺序对应上表组别）仅保留构建产物：
`FlappyBird.exe`、Qt5 运行库 DLL、`*.o`、`moc_*.cpp`、`qrc_flappy.cpp`、`ui_*.h`、`testee.txt`。
本仓库**只提交源码**（约 21 MB），不包含这些二进制产物；编译方式见根 README。

# 数据输出格式 · Data output format

## 1. 行为数据文件 `testee.txt`

被试点击"结束实验"（`choujiang.cpp → on_pushButton_3_clicked()`）时，程序以
**追加 (Append)** 方式写入**程序当前工作目录**下的 `testee.txt`：

```cpp
QFile file("testee.txt");
if (file.open(QIODevice::Append | QIODevice::Text)) {
    QTextStream out(&file);
    out << "TOTALSCORE:" << data1 << ",  CJNUM:" << data2 << endl;
    file.close();
}
```

其中 `data1 = QPos::Fscore / 2`，`data2 = CJmunber`。

### 文件示例 · Example

```text
TOTALSCORE:12,  CJNUM:9
TOTALSCORE:7,  CJNUM:4
TOTALSCORE:31,  CJNUM:22
```

### 字段说明 · Fields

| 字段 Field | 类型 | 含义 Meaning |
|---|---|---|
| `TOTALSCORE` | int | 得分。游戏内 `QPos::Fscore` 为管道计分，写出时除以 2 |
| `CJNUM` | int | 被试实际完成的**抽奖次数**（每次点击"抽奖"且抽奖次数 ≥ 0 时 +1） |

> 注意：一行 = 一名被试的一次完整实验。程序**不会**自动写入被试编号，
> 请把编号写在数据文件旁边（或在实验时把每个被试的 `testee.txt` 单独存放在以其编号命名的目录中）。

### 解析建议 · Suggested parsing

```python
import re
rows = []
with open("testee.txt", encoding="utf-8") as f:
    for line in f:
        m = re.match(r"TOTALSCORE:(\d+),\s*CJNUM:(\d+)", line.strip())
        if m:
            rows.append({"total_score": int(m.group(1)), "n_draws": int(m.group(2))})
```

---

## 2. 程序内可用的其他行为指标 · Other measures available in code

论文的因变量除抽奖次数外还包括**通过管道总数**与**游戏时长**。

| 指标 Measure | 代码位置 Location | 当前状态 Status |
|---|---|---|
| 抽奖次数 draws | `choujiang.cpp` 成员 `CJmunber` | 已写入 `testee.txt` |
| 得分 / 管道计分 pipes passed | `QPos::Fscore`（`mainwindow.cpp`） | 已写入 `testee.txt`（÷2） |
| 通过管道总数 total pipes | `QPos::Fscore` 的累计值 | 可用，未单独写出 |
| 游戏时长 time played | 主窗口游戏循环计时 | 需自行添加 `QElapsedTimer` 或 `QTime` 记录后写出 |

如需补全后两项，可在 `mainwindow.cpp` 中记录起始时间，并在
`choujiang::on_pushButton_3_clicked()` 的写文件语句中追加字段：

```cpp
out << "TOTALSCORE:" << data1
    << ",  CJNUM:" << data2
    << ",  PIPES:"  << QPos::Fscore      // 或你的累计管道数
    << ",  DURATION_MS:" << elapsed.elapsed() << endl;
```

（本仓库不擅自修改实验逻辑，以上仅为扩展建议。
*This repository deliberately does not change the recorded variables — the snippet above is a suggestion only.*）

---

## 3. 评分框数据 · Rating-dialog data

每次抽奖结果展示后会随机弹出 `pingfen` 评分框：

> 我对本次抽到结果的"想要"程度为（1 = 非常不想要，4 = 一般，7 = 非常想要）

该 1–7 评分**不会**写入 `testee.txt`。原始实验中被试的评分由主试记录 / 由后测问卷采集，
如需程序化采集，可在 `pingfen.cpp` 的确认槽函数中把分值追加写入另一个文件
（例如 `rating.txt`），并按 `choujiang.cpp` 中 `emit_pingfen1..10` 的卡片类别区分稀有 / 普通卡。

---

## 4. 目录与文件约定 · File conventions

| 文件 File | 作用 Role | 提交到仓库？ In repo? |
|---|---|---|
| `testee.txt` | 行为数据输出（被试结束后追加） | ✅ 空文件 |
| `output.txt` | 预留输出文件（当前为空） | ✅ 空文件 |
| `ui_*.h`、`moc_*.cpp`、`qrc_*.cpp`、`Makefile*`、`*.o` | 构建生成物 | ❌ 已在 `.gitignore` 中忽略 |

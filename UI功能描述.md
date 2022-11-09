# WEB端

分为三个页面

* 最新点名页
* 班级成员页
* 数据导出页

页面顶端框中居左显示“易点名”，框为蓝底。

左边一栏可以选择页面

## 首页（最新点名页）

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211081308181.png)

居左显示课程名，居右显示“xxx老师，您好”

四分数据大屏：

* 点名进度情况
* 点名到课情况
* 缺课名单
* 请假名单

## 班级成员页

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211081309713.png)

居左显示课程名，居右显示“xxx老师，您好”

显示选修该课程的学生名单以及考勤情况，并可选择排序规则进行排序：

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211081311920.png)

点击查看详情可查看学生的具体考勤情况。



## 数据导出页

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211081312711.png)

居左显示课程名，居右显示“xxx老师，您好”

显示该课程每一堂课的考勤情况，并可选择排序规则进行排序：

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211081313200.png)

提供数据导出功能，点击下方按钮可生成对应数据表格。





# 小程序端

分为学生界面与考勤人员界面

## 学生界面

分为四个界面

* 主界面（课程界面）
* 消息界面
* 我的界面
* 签到界面

### 主界面（课程界面）

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211081341365.png)

顶部居中显示“我的课程”

底部有三个选项

* 课程
* 消息
* 我的

按时间顺序显示今天要上的课程，每个课程可以点开进入到详情界面，可以进行签到或者是请假操作：

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211081329236.png)

点击签到按钮即可跳转到签到界面

点击请假按钮弹出请假框，可以填写请假事由并上传请假凭证：

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211081331504.png)

### 签到界面

![image-20221108133328508](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20221108133328508.png)

顶部显示课程名、教室、老师名字

中间放置圆形签到按钮，点击即可签到

下方放置返回按钮，点击返回到主页面

注意按钮分为两种情况：

* 督导人员已发布签到：按钮为蓝色，显示“签到”字样，点击签到成功后按钮转为绿色，显示“已签到”字样
* 督导人员未发布签到：按钮为灰色，显示“签到还未发布”字样

### 消息界面

按课程时间顺序排列，默认情况下为“无”。

缺课的课程将框底色改为红色，并显示“你缺课了！”字样。

### 我的界面

提供两个选项：

* 意见反馈与帮助
* 设置

## 督导人员界面

分为五个界面

* 主界面
* 点名界面
* 课程信息管理界面
* 消息界面
* 我的界面

### 主界面

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211081413922.png)

顶部居中显示“我的点名”

底部有三个选项：

* 点名
* 消息
* 我的

按时间顺序显示今天要点名的课程，每个课程可以点开进入到详情界面，可以进行点名操作或查看历史点名记录：

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211081349724.png)

点击右下角齿轮可以跳转至课程信息管理界面

### 点名界面

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211081352530.png)

顶部显示课程名、教室、老师名字

中间上方放置圆形名单点名按钮，点击即可利用名单进行点名

中间下方放置圆形定时发布按钮，点击即可发布定时签到任务

#### 名单点名

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211081354605.png)

共三个子界面

* 未点
* 缺课
* 统计

##### 未点

默认即为未点界面

##### 缺课

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211081357894.png)

显示所有缺课同学的学号姓名

上方搜索框可根据学号或姓名搜索到相应同学

点击不同按钮可以改变状态：

* 迟到：框变为黄色
* 到课：框变为蓝色
* 请假：框变为绿色

再次点击缺课界面可进行刷新，显示最新状态。

##### 统计

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211081401838.png)

如上图

### 课程信息管理界面

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211081415181.png)

点击课程可以进行课程信息的修改：

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211081416940.png)

点击右下角加号可以添加课程：

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211081418016.png)

### 消息界面

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211081418518.png)

根据课程顺序显示学生的请假、申诉信息



### 我的界面

同学生界面，提供两个选项：

* 意见反馈与帮助
* 设置






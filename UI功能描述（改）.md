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



一些颜色的RGB

* 用于导航框和标题框的淡蓝色 #DAEBFE
* 用于示警的淡红色 #FF8E8E
* 学生签到界面
  * 提示签到状态的浅蓝色 #B5D8FF
  * 已签到状态的浅绿色 #BFFFA2
* 选择时间的三种状态
  * 淡蓝色 #C9E2F9
  * 淡绿色 #C9F9D6
  * 淡黄色 #FDFDC9
* 缺课界面方块的颜色
  * 迟到 #E99D42
  * 到课 #1784FC
  * 缺课 #BD3124
  * 请假 #81B337

没给RGB的自己配配，差不多就行



## 学生界面

分为五个界面

* 主界面（课程界面）
* 消息界面
* 请假界面
* 我的界面
* 签到界面

### 主界面（课程界面）

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211131349226.png)

顶部居中显示“我的课程”，底色为淡蓝色（颜色RGB详见小程序端开头）

底部有四个选项

* 课程
* 请假
* 消息
* 我的

按时间顺序显示今天要上的课程，每个课程可以点开进入到详情界面，可以进行签到操作：

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211131350944.png)

点击签到按钮即可跳转到签到界面。

### 签到界面

![image-20221108133328508](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20221108133328508.png)

顶部显示课程名、教室、老师名字

中间放置圆形签到按钮，点击即可签到

下方放置返回按钮，点击返回到主页面

注意按钮分为两种情况：

* 督导人员已发布签到：按钮为蓝色，显示“签到”字样，点击签到成功后按钮转为绿色，显示“已签到”字样
* 督导人员未发布签到：按钮为灰色，显示“签到还未发布”字样

### 请假界面

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211131343563.png)

分为左右两列。

左列为请假详情，显示起始时间与结束时间。

右列为审核状态，分别为审核通过（浅绿色底色）、审核中（无底色）、审核未通过（浅红色底色）。

点击右下角加号可以新增请假申请

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211131345862.png)

下拉选择起始时间与结束时间，并提供输入请假理由和上传请假凭证的功能，点击确定按钮提交。



### 消息界面

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211131347690.png)

按获取消息的时间从新到旧进行排序，分为左右两列。

左列为消息内容，右列为消息发布者。

缺课消息将框底色改为红色。

### 我的界面

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211131350228.png)

展示头像、学生名字、学号、所属学院、专业。

并提供两个选项：

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

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211131357970.png)

点击右下角加号可以添加课程：

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211131358367.png)

点击选择时间，跳转到可以选择时间的页面：

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211131358517.png)

每个方块代表一个时间段，且每个方块都可进行点击：

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211131359434.png)

共有四种状态：

* 不点击，默认白色，代表不上课
* 点击一次，变为淡蓝色，代表单双周均上课
* 点击两次，变为淡绿色，代表仅在奇数周上课
* 点击三次，变为淡黄色，代表仅在偶数周上课
* 在淡黄色状态下再点击一次，回到默认状态

### 消息界面

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211131402786.png)

分为左右两列

左列为消息内容；

右列为消息发布者；

消息分为两种情况

* 其他督导队员发来的

点击消息可查看详情，并可对可疑操作点选不合理进行驳回：

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211131403805.png)

点击操作详情下方的文本框，可以查看具体消息日志：

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211131404972.png)

* 学生发来的

点开可查看消息内容，并对其进行审核：

![](https://godot-pics.oss-cn-fuzhou.aliyuncs.com/202211131406624.png)



### 我的界面

与学生端一致

展示头像、学生名字、学号、所属学院、专业。

并提供两个选项：

* 意见反馈与帮助
* 设置






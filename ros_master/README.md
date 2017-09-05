# MASTER_API
## 說明
使用`ros/master.h`中的函數來獲得有關ROS的資訊。
包含:
 * 主機名稱
 * 主機URI
 * topic名稱及型態
 * port
## 注意

在`ros/master.h`中的`getTopics`只能列出有publish資料的topic，而未被publish的topic則無法獲得。

```
  This method communicates with the master to retrieve the list of all
  currently advertised topics.
```



## 參考資料
[getrostopic](https://answers.ros.org/question/53267/get-all-topics-in-c/)

# swift 相關資訊收集

## JSONParsing

* swift 4 以後官方有直接支援，參考如下
  * [JSON Parsing in Swift](https://medium.com/@nimjea/json-parsing-in-swift-2498099b78f)

## 前置定義的設定

* swift 的設定跟 objective-c 的不同
* [Target][Build Settings][Swift Complier - Custom Flags] [Other Swift Flags]
* 參考
  * [#ifdef replacement in the Swift language](https://stackoverflow.com/questions/24003291/ifdef-replacement-in-the-swift-language)
  * [Swift中如何使用 #if DEBUG](https://www.cnblogs.com/Bob-wei/p/5237761.html)

---

## Load File

* 以下為 sample code

``` swift
    // 設定 URL path.
    let srcConfigFileURL: URL = URL(fileURLWithPath: NSHomeDirectory() + "/Desktop/temp/catTest.json")

    // load file from URL to Data
    let jsonData: Data = try Data(contentsOf: srcConfigFileURL)
```

## TODO

* guard 語法
* struct & class difference

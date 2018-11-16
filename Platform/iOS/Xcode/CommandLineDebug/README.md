# CommandLine Debug 設定

* 使用情境
  
 > 在command line專案中，有時會處理 command line 的 argument。
 >
 > 此時在debug階段時，會想要直接下中斷點來看command line 的帶入參數。
 >
 > 遇此狀況時可用下列的步驟來模擬實際上的參數。

---

## 設定方式如下

* step1 (Edit Scheme)
  
  ![step1](./pics/01.png)

* step2 [Run][Arguments]
  
  ![step2](./pics/02.png)

* step3 (選擇新增參數)
  
  ![step3](./pics/03.png)

* step4 (輸入要測試的參數)
  
  ![step4](./pics/04.png)

* step5 (執行 Run 的結果，有下中斷點)
  
  ![step5](./pics/05.png)

---

## 透過上述的方式即可下中段驗證剖析參數是否如預期方式

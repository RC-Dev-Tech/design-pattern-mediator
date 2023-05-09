# ![](https://drive.google.com/uc?id=10INx5_pkhMcYRdx_OO4rXNXxcsvPtBYq) Mediator 中介者模式
> ##### 理論請自行找，網路上有很多相關的文章，這邊只關注於範例實作的部分.

---

<!--ts-->
## 目錄
* [目的](#目的)
* [使用時機](#使用時機)
* [URL結構圖](#url結構圖)
* [實作成員](#實作成員)
* [實作範例](#實作範例)
* [參考資料](#參考資料)
<!--te-->

---

## 目的
Mediator 設計模式用於將一個對象的交互行為封裝到一個中介對象中，以促進對象之間的鬆散耦合。<br>
透過中介者模式，我們可以減少對象之間的直接耦合，從而提高系統的可維護性和可擴展性。

---

## 使用時機
當一個系統由許多相互依賴的對象組成，並且這些對象需要相互通信時，可以使用中介者模式。<br>
這種模式對於減少對象之間的直接依賴關係，提高對象之間的松散耦合非常有用。

---

## URL結構圖
![](https://drive.google.com/uc?id=19MOdu_oTpqXq5q4f4Ec_9B9lAvePQaxR)
> 圖片來源：[Refactoring.Guru - Mediator](https://refactoring.guru/design-patterns/mediator)

---

## 實作成員
* Mediator（中介者）
  * 定義了一個接口，用於與各個同事對象之間進行通信。
* ConcreteMediator（具體中介者）
  * 實現了中介者接口，對象之間的相互通信必須通過中介者進行。
* Colleague（同事類）
  * 定義了一個接口，用於與中介者對象進行通信。
* ConcreteColleague（具體同事類）
  * 實現了同事類接口，對象之間的相互通信必須通過中介者進行。

---

## 實作範例:
- [待補...]() 

---

## 參考資料
* [Wiki - Mediator Pattern](https://en.wikipedia.org/wiki/Mediator_pattern) <br>
* [Refactoring.Guru - Mediator](https://refactoring.guru/design-patterns/mediator) <br>

---

<!--ts-->
#### [目錄 ↩](#目錄)
<!--te-->
---

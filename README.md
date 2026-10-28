# VSA1 - Laboratoriya işi 3 (Lab 3)

**Tələbə:** Səid Saruxanov  
**Mövzu:** Əlaqəli siyahı əsasında növbə strukturları

Bu repozitoriyada C++ dilində qovşaqlar (nodes) və göstəricilər (pointers) vasitəsilə qurulmuş iki növbə tətbiqi təqdim olunur. Hazır STL konteynerlərindən (`queue`, `list` və s.) istifadə edilmir.

## Tapşırıqlar və istifadə olunan məlumat strukturları

### 1. Task 1: Müştəri və dərman növbəsi (`task1.cpp`)

* **Məlumat strukturu:** Əlaqəli siyahı əsaslı növbə (*Linked List-based Queue*, FIFO).
* **Təsvir:** Hər qovşaqda müştərinin adı və dərmanın adı saxlanılır. Növbə `initQueue` ilə başladılır, `enqueue` yeni müştərini sona əlavə edir, `dequeue` ön sıradakı müştəriyə xidmət göstərərək onu növbədən çıxarır, `isEmpty` növbənin boşluğunu yoxlayır və `printQueue` növbədə qalan müştəriləri göstərir.
* **Nümunə:** Eli/Parasetamol, Aysel/Aspirin və Murad/Analgin növbəyə əlavə olunur; Eli-yə xidmət göstərildikdən sonra qalan növbə çap edilir.

### 2. Task 2: Yaşa görə sərnişin növbələri (`task2.cpp`)

* **Məlumat strukturu:** İki əlaqəli siyahı əsaslı növbə (*Linked List-based Queue*).
* **Təsvir:** `BusStop` prioritetli və adi növbələri bir yerdə saxlayır. `AddPassenger` yaşı 45-dən böyük olan sərnişinləri prioritetli növbəyə, digərlərini isə adi növbəyə əlavə edir. `Enqueue` növbənin sonuna əlavə etmə, `Dequeue` növbənin önündən çıxarma, `isEmpty` boşluq yoxlaması, `printQueue` isə növbənin çapı üçün istifadə olunur.
* **Nümunə:** 45 yaşdan böyük sərnişinlər prioritetli, qalan sərnişinlər adi növbədə göstərilir. Proqram hazırda sərnişinləri iki növbəyə ayırıb çap edir; `Dequeue` funksiyası ayrıca əməliyyat kimi reallaşdırılıb.

## Kompilyasiya və işə salma

GCC ilə hər tapşırığı ayrıca kompilyasiya edib işə salmaq olar:

```bash
g++ task1.cpp -o task1
./task1

g++ task2.cpp -o task2
./task2
```

## Funksiyaların ekran görüntüləri

Şəkillər hər bir funksiyanı ayrıca çağıran yoxlama proqramlarının çıxışını göstərir.

### Task 1

* [`initQueue`](screenshots/task1_initQueue.png)
* [`isEmpty`](screenshots/task1_isEmpty.png)
* [`enqueue`](screenshots/task1_enqueue.png)
* [`dequeue`](screenshots/task1_dequeue.png)
* [`printQueue`](screenshots/task1_printQueue.png)

### Task 2

* [`initQueue`](screenshots/task2_initQueue.png)
* [`isEmpty`](screenshots/task2_isEmpty.png)
* [`Enqueue`](screenshots/task2_Enqueue.png)
* [`Dequeue`](screenshots/task2_Dequeue.png)
* [`printQueue`](screenshots/task2_printQueue.png)
* [`initBusStop`](screenshots/task2_initBusStop.png)
* [`AddPassenger`](screenshots/task2_AddPassenger.png)

## Süni intellekt (AI) bəyannaməsi

Bu `README.md` faylının məzmunu layihənin hazırkı koduna uyğunlaşdırılaraq GitHub Copilot-un köməyi ilə hazırlanıb.

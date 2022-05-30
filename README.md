# Satranç Oyunu

##### Problem tanımı:
Satranç tahtası üzerinde bulunan taşlara göre iki tarafın (siyah – beyaz) mevcut durumlarının puan hesaplaması.

##### Açıklama:
Mevcut puanı hesaplama algoritması şöyledir:
1. Bir taşın tehdit altında olup olmadığının kontrolü, o taşı tehdit eden karşı renkte bir veya birden fazla taş olması durumunda oluşur.
2. *Tablo 1* ’de taşların puanları verilmiştir. Eğer bir taş **tehdit edilmiyorsa** tablodaki puanı alır.
3. Eğer bir taş karşı tarafın taşlarından herhangi biri tarafından **tehdit ediliyorsa**, tehdit edilen taşın puanı *Tablo 1* ’deki puanının yarısı alınır.
4. Tüm taşların tehdit durumları kontrol edilir. Siyah ve beyaz taşlar için iki ayrı puan hesaplanır.

#### Tablo 1 Satranç Taşları ve Puanları:

| Taş İsmi | Kısaltma | Puanı | 
| ------ | ------ | ------ |
| Piyon | p | 1 | 
| At | a | 3 | 
| Fil | f | 3 | 
| Kale | k | 5 | 
| Vezir | v | 9 | 
| Şah | s | 100 | 

##### Örnek puan hesaplaması:
![board1](https://github.com/mrterdll/SatrancOyunu/blob/748bebb0910364a360722c61e6c9607e6574ea5e/board1.png?raw=true)
*Figure 1*

Figure 1’de puan hesabı; tehdit altında olan taşlara göre şöyle hesaplanabilir:
Siyah = (3*0.5)+(4*1)+(1*1.5)+(1*3)+(3*2)+(5*2)+9+100 = 135,
Beyaz = (1*0.5)+(6*1)+(1*1.5)+(1*3)+(1*1.5)+(1*3)+(5*2)+9+100 = 134.5

##### Program Girdileri:
Örnek oyun tahtasının formatı aşağıda verilmiştir.
> ks as fs vs ss fs -- ks
> ps ps -- -- ps ps -- ps
> -- -- ps -- -- -- -- --
> -- -- -- as -- -- ps --
> vb -- -- pb -- fb -- pb
> -- -- ab -- -- -- -- --
> pb pb -- -- pb pb pb --
> kb -- -- -- sb fb ab kb

- Burada ilk harf taş bilgisini (Tablo 1’de verilmiştir.) ikinci harf ise renk bilgisini, -- ile ifade edilen yerler ise tahtadaki boş alanları göstermektedir.
- Program girdilerinin her zaman doğru formatta ve doğru karakterlerle verileceğini varsayınız.
```sh
boardFile.open("board1.txt", ios::in);
```
- Yukarıdaki örnekte görüldüğü gibi input dosyasının girdisi verilmelidir.
```sh
double* getScore(string arr[8][8]);
```
- getScore() fonksiyonunu kullanarak siyah ve beyaz taşlar için puan hesabı yapılabilir.
```sh
void printBoard(string arr[8][8]);
void printBoard(bool arr[8][8]);
```
- Yukarıdaki printBoard() fonksiyonu kullanılarak oyun tahtasındaki taşların konumları ekrana bastırılabilir veya alttaki printBoard() fonksiyonu kullanılarak tehdit altında olan taşların konumları ekrana bastırılabilir.

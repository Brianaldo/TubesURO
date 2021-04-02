TUBES PROGRAMMING
Brianaldo Pradiarta (1652010) dan Suryanto (16520195)

Pengoperasioan robot:
1.	Robot akan mulai pada koordinat (0,0) sedangkan kecoak akan muncul pada koordinat sembarang didalam jangkauan 20x20, tetapi tidak dititik yang tepat dengan robot
2.	Robot memiliki atribut health sebesar 100 poin dan damage sebesar 5 poin. Sedangkan kecoak memiliki atribut health sebesar 20 poin dan damage sebesar 5 poin
3.	Robot dapat menerima masukan berupa bilangan 1-6 dengan fungsi sebagai berikut:
    a.	1 = Robot bergerak 1 titik ke atas
    b.	2 = Robot bergerak 1 titik ke bawah
    c.	3 = Robot bergerak 1 titik ke kanan
    d.	4 = Robot bergerak 1 titik ke kiri
    e.	5 = Robot menembakkan senjatanya
    f.	6 = Robot menyerah
4.	User memberikan masukan 1-4. Misalnya masukan meminta robot untuk keluar dari peta (20x20) atau menabrak kecoak. Pesan invalid akan dimunculkan dan user diminta untuk memberikan masukan baru. Kecoak tidak akan mendekat/menyerang apabila masukan bagian ini bersifat invalid
5.	Robot dapat menembak kecoak dengan jangkauan maksimal 3 titik, tetapi hanya dapat menembak sejajar sumbu x atau sejajar sumbu y, tidak dapat diagonal. Jika kecoak berada di luar jangkauan, akan dimunculkan pesan “tembakan meleset” dan kecoak tetap mendapatkan gilirannya, baik untuk menyerang maupun mendekat.
6.	Kecoak dapat menyerang robot dalam jangkauan 1x1, artinya ia dapat menyerang apabila robot tepat berada didepannya sejajar sumbu x/sumbu y, atau tepat berada didepannya secara diagonal (jarak vektor keduanya sebesar (1,1)).
7.	Program akan selesai apabila health robot mencapai 0 atau robot memilih untuk menyerah

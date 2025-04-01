# Object Oriented Programming Dersi Uygulamaları ve Dönem Sonu Projesi
Bu repo, **Object Oriented Programming** dersi için yaptığım ders içi uygulamalar ve dönem sonu projesini içermektedir.

## Uygulamalar
- **Uygulama 1:** input.txt dosyasından tam sayıları okur, toplamını, çarpımını, ortalamasını ve en küçüğünü hesaplar. Fonksiyonlar ve dosya okuma ile Git’te en az 3 commit içerir.
- **Uygulama 2:** HackerRank’taki 17 C++ problemini çözer, her çözüm .cpp dosyasına kaydedilip Git’e eklenir. Sınıf ve nesne pratiği için çift programlama kullanılır.
- **Uygulama 3:** input.txt’den büyük sayılarla toplama, çıkarma ve çarpma yapar. İşlemleri sınıflarla yönetir ve sonuçları tam formatta ekrana yazar.
- **Uygulama 4:** Komut dosyasından motor ve yakıt tankı sistemini simüle eder. UML diyagramı ile sınıfları uygular, mantık main’de değil sınıflarda yer alır.
- **Uygulama 5:** Motor ve sınırsız yakıt tankıyla komutları simüle eder, UML ve Singleton kullanır. Yakıt tüketimi ve tank bilgilerini stop_simulation ile yönetir.
- **Uygulama 6:** X-sample.zip içindeki problemleri çözer, her çözüm ayrı ayrı Git’e commit edilir. Yeni metodlarla modüler tasarım yapılır, mantık main’de değil sınıflardadır.
- **Uygulama 7:** TakeHome-5’i genişletir, stop_simulation ile her nesne mesaj yazar. 3 tank, 3 valf ve 1 motor için durdurma mesajları ekrana basılır.
- **Uygulama 8:** TakeHome-5 kodunu verilen UML’e göre baştan düzenler veya yeniden yazar. Sınıf yapısını UML ile uyumlu hale getirir.

## Dönem Sonu Projesi
- **Proje Adı:** İnsansı Robot Denetim Sistemi
- **Amaç:** Webots simülatöründeki insansı robotun hareketlerini kontrol etmek ve sensör verilerini yönetmek için nesne tabanlı bir yazılım geliştirmek; erişim kontrolü, yol planlama ve veri kaydı ile sistemi genişletmek.
- **İşleyiş:** Kullanıcı, konsol tabanlı metin menüleri üzerinden robotu bağlar/keser, hareket komutları (ileri, geri, dönme, yan adım) verir, sensör verilerini (sonar, bumper, force) görüntüler veya dosyaya kaydeder; yol planını oluşturur ve yönetir.
- **Menü Yapısı:** Ana menüde "Connection", "Motion", "Sensor" ve "Quit" seçenekleri bulunur; alt menülerde bağlantı yönetimi, hareket komutları ve sensör işlemleri yer alır; tüm erişim şifreyle korunur.
- **Erişim Kontrolü:** RobotOperator sınıfıyla 4 rakamlı şifreleme kullanılır; openAccess ile erişim açılır, closeAccess ile kapanır; şifresiz komutlar çalışmaz.
- **Veri Yönetimi:** Robotun konumu (Pose) Path sınıfıyla listelenir ve Record sınıfıyla dosyaya kaydedilir; sensör verileri (recordSensor) tipi belirtilerek dosyaya yazılır.
- **Görsel Çıktı:** Konsolda, her komut sonrası robotun konumu, sensör verileri ve yol planı düzenli bir formatta yazdırılır; menüler kullanıcı dostu bir arayüz sunar.

## Notlar
- Proje iki aşamada geliştirilmiştir: 1. aşamada temel sınıflar ve menü sistemi oluşturulmuş; 2. aşamada RobotInterface ve SensorInterface ile soyutlama eklenmiş, erişim kontrolü ve yeni fonksiyonlar ile sistem revize edilmiştir.
- Nesne tabanlı programlama ilkeleri (abstraction, inheritance, polymorphism, exception handling) uygulanmış; tüm sınıflar ayrı .h ve .cpp dosyalarında Doxygen yorumlarıyla belgelenmiştir.
- Lab uygulamalarının isterleri, her bir uygulama klasöründe PDF formatında paylaşılmıştır; yapılan çalışmalar ilgili dosyalarda yer almaktadır.

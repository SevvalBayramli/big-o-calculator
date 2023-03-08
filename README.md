# Big O Notasyonu Hesaplayıcı

Bu program, belirli bir algoritmanın Big O notasyonunu hesaplamak için C programlama dilinde yazılmıştır.

## **Kullanım**

- İlk olarak, **`dosya.txt`** dosyasını oluşturun ve içerisine hesaplamak istediğiniz kod parçasını yapıştırın.
- Programı derlemek için, aşağıdaki terminal komutunu kullanın:

```bash
gcc -o program BigOCalculator.c
```

- Program, kullanıcıdan belirli bir algoritmanın işlem sayısını alacak ve Big O notasyonunu hesaplayacak.

## **Örnek Kod**

Aşağıdaki örnek kodu kullanarak programı test edebilirsiniz:

```c
#include <stdio.h>int main()
{
    int n = 10; // n elemanlı bir dizi
    int dizi[n];

    for (int i = 0; i < n; i++) {
        dizi[i] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("(%d, %d)\n", dizi[i], dizi[j]);
        }
    }

    return 0;
}
```

Bu kod, bir dizi içindeki tüm elemanların her biri ile birlikte diğer tüm elemanların çiftlerini yazdıracaktır. Bu kod, bir $O(n^2)$ karmaşıklığına sahiptir.

## **Katkıda Bulunma**

Bu proje açık kaynaklıdır ve herhangi bir katkıda bulunma isteğine açıktır. Eğer projeye katkıda bulunmak istiyorsanız, lütfen GitHub sayfamızı ziyaret edin ve bir pull request gönderin.



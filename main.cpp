#include "hashcounter.h"
#include <assert.h>
using namespace std;

int main()
{
    hashCounter <string> ht,ht1;

       // Добавляем в неё различные идентификаторы
       ht.add("a");
       ht.add("aa");
       ht.add("if");
       ht.add("fi");
       ht.add("fi");
       ht.add("aa");
       ht.add("grrrr");
       ht.add("rrrr");
       ht.deletKey("fi");
       assert(ht["a"]==1);
       assert(ht.numObjects()==6);
       hashCounter<string> ht2(ht);
       assert(ht.numObjects()==ht2.numObjects());
       assert(ht.m_hash_table==ht2.m_hash_table);
       ht2.clearCounter();
       assert(ht2.numObjects()==ht1.numObjects());
       assert(ht2.m_hash_table==ht1.m_hash_table);

    // Выводим на экран информацию о различных идентификаторах
    std::cout << ht.get("a").getName()<< std::endl;
    std::cout << ht.get("aa").getName() << std::endl;
    std::cout << ht.get("if").getName() << std::endl;
    std::cout <<ht.get("aa").getCounter()<<std::endl;
    std::cout <<ht.get("fi").getCounter()<<std::endl;
    // Проверяем случай, когда идентификатор не должен быть найд
     hashCounter<int> ht3;
     ht3.add(1);
     ht3.add(11);
     ht3.add(35);
     ht3.add(35);
     ht3.add(12);
     ht3.deletKey(12);
     std::cout << ht3.get(1).getName()<<std::endl;
     std::cout << ht3.get(11).getName()<<std::endl;
     std::cout << ht3.get(35).getName()<<std::endl;
     std::cout <<ht3.get(35).getCounter()<<std::endl;
     std::cout <<ht3.get(12).getCounter()<<std::endl;
     hashCounter<string> htt1,htt2,htt3,htt4;
     htt1.add("A");
     htt1.add("AA");
     htt2.add("A");
     htt2.add("l");
     htt3.add("A");
     htt3.add("A");
     htt3.add("AA");
     htt3.add("l");
     assert(htt2.numObjects()==2);
     assert(htt2.isInCounter("l"));
     htt4=htt1||htt2;
     assert(htt4==htt3);
     htt4 >>("pov.txt");
     htt3 <<("pov.txt");
     assert(htt4==htt3);
     htt4.printData();
     htt3.printData();
     return 0;
}

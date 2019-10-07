#include <stdio.h>
#include <iostream>
#include <memory.h>

// class Foo {
// public:
//     Foo() {
//         // printf("Foo:Foo()\n");
//         // sayHello();
//     }
//     virtual ~Foo() {
//         // printf("Foo:~Foo()\n");
//     }
//     virtual void sayHello() {
//         printf("Foo:sayHello\n");
//     }
// };

// class childFoo : public Foo {
// public:
//     childFoo() {
//         // printf("childFoo:childFoo()\n");
//         // sayHello();
//         // mStr = new char[10];
//     }
//     virtual ~childFoo() {
//         // printf("childFoo:~childFoo()\n");
//         // delete mStr;
//         // mStr = 0;
//     }
//     virtual void sayHello() {
//         printf("childFoo:sayHello()\n");
//     }
// private:
//     char *mStr;
// };

// typedef void (Foo::*fSayHello)();


// class Foo {
// public:
//     Foo() {
//         printf("Foo:Foo()");
//         sayHello();
//     }
//     ~Foo() {
//         delete this;
//     }
//     virtual void sayHello() {
//         printf("Foo:sayHello");
//     }
// };

// class childFoo : public Foo {
// public:
//     childFoo() {};
//     inline virtual ~childFoo() {}
// };

// const char* g_str1 = 0;
// const char* g_str2 = 0;
// static void foo1(void) {
//     g_str1 = "hello1";
// }
// static void foo2(void) {
//     char p[] = "hello2";
//     g_str2 = p;
// }

typedef struct foo
{
    short magic;
    int version;
}foo_t;


int main()
{
    // childFoo a;

    // Foo* p = new Foo();
    // p->sayHello();
    // delete p;

    // childFoo* cFoo = new childFoo();
    // Foo* foo = cFoo;
    // foo->sayHello();
    // delete foo;

    // Foo foo;
    // childFoo cfoo;
    // fSayHello say = Foo::sayHello;
    // (foo.*say)();
    // (cfoo.*say)();

    // foo1();
    // foo2();
    // printf("%p: %s\n", g_str1, g_str1);
    // printf("%p: %s\n", g_str2, g_str2);

    foo_t a1;
    foo_t a2;
    a1.magic = a2.magic = 1;
    a1.version = a2.version = 2;
    if (0 == memcmp(&a1, &a2, sizeof(foo_t))) {
        printf("*foo_t a1 is equal to a2\n");
    }

    foo_t a0 = {0};
    short * ptr = &(a0.magic);
    printf("%d %x %x %x %x\n", sizeof(foo_t), *ptr, *(ptr+1),  *(ptr+2), *(ptr+3));
    // } else
    // {
    //     printf("a1.m=%c, a1.v%c, a2.m%c, a2.v%c", a1.)
    // }


    return 0;
}

// 22cd 23a 24c
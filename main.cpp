#include "rsa.h"


void teststring()
{
    RSA RSA;
    Key key = RSA.GetKey();
    std::string str;
    std::cout << "输入需要加密的字符：" << std::endl;
    getchar();
    std::getline(std::cin,str);
    //对输入进行加密
    std::vector<bm::int1024_t>str_ec = RSA.Ecrept(str,key.ekey,key.nkey);
    std::string str_de = RSA.Decrept(str_ec,key.dkey,key.nkey);
    std::cout << "密文：" << std::endl;
    std::cout << str_de << std::endl;
    return;    
}

void testFile()
{
    RSA RSA;
    Key key = RSA.GetKey();
    std::string filename;
    std::cout << "请输入需要加密的文件:" << std::endl;
    std::cin >> filename;
    RSA.FileEcrept(filename.c_str(),(filename + "ecrept.out.txt").c_str(),key.ekey, key.nkey);
    std::cout << "加密完成！" << std::endl;
    RSA.FileDecrept((filename + "ecrept.out.txt").c_str(),(filename + "decrept.out.txt").c_str(),key.dkey,key.nkey);
    std::cout << "解密完成！" << std::endl;
    return;
}

int main()
{
    int n;
    do
    {
        std::cout << "输入需要加密的类型：" << std::endl;
        std::cout << "1、字符" << std::endl;
        std::cout << "2、文件" << std::endl;
        std::cout << "3、退出" << std::endl;
        std::cin >> n;
        if(n == 1)
        {
            teststring();       
        }
        else if (n == 2)
        {
            testFile();
        }
        else if (n == 3)
        {
            break;
        }
        else
        {
            std::cout << "输入错误！" << std::endl;
        }  
    } while (n);
    return 0;
}
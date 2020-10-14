#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>


//boost库中的方法
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/random.hpp>
#include <boost/multiprecision/miller_rabin.hpp>

namespace bm = boost::multiprecision;
namespace br = boost::random;

struct Key
{
    //公钥 （nkey,ekey)
    bm::int1024_t nkey;     //n
    bm::int1024_t ekey;     //e
    //私钥（dkey，nkey）
    bm::int1024_t dkey;     //d
};

class RSA
{
public:
    RSA();
    Key GetKey();
    void FileEcrept(const char* plain_file_in,const char* ecrept_file_out,
        bm::int1024_t ekey,bm::int1024_t nkey);
    void FileDecrept(const char* ecrept_file_in,const char* plain_file_out,
        bm::int1024_t dkey,bm::int1024_t nkey);

    std::vector<bm::int1024_t> Ecrept(std::string& str_in,bm::int1024_t ekey,bm::int1024_t nkey);
    std::string Decrept(std::vector<bm::int1024_t>& ecrept_str,bm::int1024_t dkey,bm::int1024_t nkey);

    void PrintInfo(std::vector<bm::int1024_t>& ecrept_str);

private:
    //对单个信息进行加密
    bm::int1024_t ecrept(bm::int1024_t msg,bm::int1024_t key,bm::int1024_t pkey);
    //获得最大素数
    bm::int1024_t Produce_Prime();
    //判断是否是素数
    bool is_prime(bm::int1024_t prime);
    //获得钥匙
    void Produce_Keys();
 
    bm::int1024_t Produce_Nkey(bm::int1024_t prime1,bm::int1024_t prime2);
    
    bm::int1024_t Produce_Oral(bm::int1024_t prime1,bm::int1024_t prime2);

    bm::int1024_t Produce_Ekey(bm::int1024_t oral);

    //获取公约数
    bm::int1024_t Produce_Gcd(bm::int1024_t ekey,bm::int1024_t oral);
    bm::int1024_t Produce_Exgcd(bm::int1024_t ekey,bm::int1024_t oral,bm::int1024_t& x,bm::int1024_t& y);
    bm::int1024_t Produce_Dkey(bm::int1024_t ekey,bm::int1024_t oral);
private:
    Key _key;
};
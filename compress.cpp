#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <array>

std::vector<double> evaluate(std::vector <double> &image, long n)
{
    //    std::random_device rng;
    std::mt19937 urng;
    std::uniform_real_distribution<> dis(0., 1.);

    std::vector<double> ret;
        
    for (long i = 0; i != n; i++)
    {
        std::vector<double> rnd (image.size(), 0.);
        double totrnd = 0.;
        for (auto &&i : rnd)
        {
            i = dis(urng);
            totrnd += i;
        }
        for (auto &&i : rnd)
        {
            i /= totrnd;
        }
        
        double r = 0.;
        for (unsigned i = 0; i != image.size(); i++)
        {
            r += rnd[i] * image[i];
        }
        ret.push_back(r);
    }
    
    return ret;
}

std::vector<double> construct(std::vector<double> sample, long w)
{
    //    std::random_device rng;
    std::mt19937 urng;
    std::uniform_real_distribution<> dis(0., 1.);

    std::vector<double> ret(w, 0.);
        
    
    for (auto &&i : sample)
    {
        std::vector<double> coeff(w, 0.);
        double totcoeff = 0.;    
        for (auto &&j : coeff)
        {
            j = dis(urng);
            totcoeff += j;
        }
        
        for (auto &&j : coeff)
        {
            j /= totcoeff;
        }
        
        for (unsigned j = 0; j != coeff.size(); j++)
        {
            ret[j] += coeff[j] * i;
        }
    }
/*
    for (auto &&j : totcoeff)
    {
        j[0] /= totcoeff[0];
        j[1] /= totcoeff[1];            
        j[2] /= totcoeff[2];            
    }
*/
    return ret;
}


int main(int, char **)
{
    std::random_device rng;
    std::mt19937 urng(rng());
    std::uniform_real_distribution<> dis(0., 1.);
    
    int k = -19;
    std::vector <double> img(39, 0.);
    for (auto &&i : img)
    {
        i = k++;
    }
    
    auto sample = evaluate(img, 100000);
    auto imgdeconvol = construct(sample, 39);

    for (auto &&i : img)
    {
        std::cout << i << std::endl;
    }
    std::cout << std::endl;

    for (auto &&i : imgdeconvol)
    {
        std::cout << i/20. << std::endl;
    }
    std::cout << std::endl;

    return 0;
}


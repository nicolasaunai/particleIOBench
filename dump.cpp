#include <stdio.h>
#include <chrono>
#include <vector>
#include <string>


  template<std::size_t dim>
    struct Particle
    {
    };



    template<>
    struct Particle<1>
    {
        double weight;
        double charge;

        int iCell[1] = {0};
        float delta[1] = {0.0f};
        double v[3] = {0., 0., 0.};

        double Ex = 0, Ey = 0, Ez = 0;
        double Bx = 0, By = 0, Bz = 0;

        static const std::size_t dimension = 1;
    };




    template<>
    struct Particle<2>
    {
        double weight;
        double charge;

        int iCell[2]= {0, 0};
        float delta[2] = {0.0f, 0.0f};
        double v[3] = {0., 0., 0.};

        double Ex = 0, Ey = 0, Ez = 0;
        double Bx = 0, By = 0, Bz = 0;

        static const std::size_t dimension = 2;
    };



    template<>
    struct Particle<3>
    {
        double weight;
        double charge;

        int iCell[3] = {0, 0, 0};
        float delta[3]  ={0.f, 0.f, 0.f};
        double v[3] = {0., 0., 0.};

        double Ex = 0, Ey = 0, Ez = 0;
        double Bx = 0, By = 0, Bz = 0;

        static const std::size_t dimension = 3;
    };

int main(int argc, char **argv)
{
    auto f = fopen("test.dat", "w");
    auto particle_s = sizeof(Particle<3>);
    auto len=std::atoi(argv[1]);

    for (auto iter=100; iter < len; iter+=100)
    {
        std::vector<Particle<3>> v(iter);
        using Clock = std::chrono::high_resolution_clock;
        auto start = Clock::now();
        fwrite(v.data(),particle_s, v.size(),f );

        auto end = Clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>
                             (end-start).count();

        printf("%d,%f\n", iter, duration/1e6);
    }
 
    fclose(f);

}

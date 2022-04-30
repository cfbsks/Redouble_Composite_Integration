#include <iostream>
#include <iomanip>
#include <math.h>
#include <functional>
#include <vector>

using namespace std;
int main()
{
    double sample_a = 0, sample_b = 3.0;
    double epsilon_sample = 0.000001;
    const double function_square(const double &x);
    const double function_special(const double &x);

    const double trapzoid_integration(const double function(const double &), const double &range_a, const double &range_b);
    const double composite_redouble_integration(const double &range_a, const double &range_b, const double &epsilon, const long long &max_times, const double function(const double &), const double integration(const double _function(const double &), const double &_range_a, const double &_range_b));
    void display_ans(const double &low_limit, const double &up_limit, const double &ans);

    double res = composite_redouble_integration(sample_a, sample_b, epsilon_sample, 1000, function_special, trapzoid_integration);
    display_ans(sample_a, sample_b, res);
}

const double function_square(const double &x)
{
    return pow(x, 2);
}

const double function_special(const double &x)
{
    double x2 = x * x;
    double res = x2 / pow((x2 - 3 * x + 3), 2);
    return res;
}

const double trapzoid_integration(const double function(const double &), const double &range_a, const double &range_b)
{
    return (function(range_a) + function(range_b)) * (range_b - range_a) / 2.0;
}

const double composite_redouble_integration(const double &range_a, const double &range_b, const double &epsilon, const long long &max_times, const double function(const double &), const double integration(const double _function(const double &), const double &_range_a, const double &_range_b))
{
    double res_old, res;
    res = integration(function, range_a, range_b);
    double h = range_b - range_a;
    double times = 0;
    do
    {
        res_old = res;
        times++;
        h /= 2.0;
        res = 0;
        for (long long i = 0; range_b > range_a + h * i; i++)
        {
            double mini_a = range_a + h * i;
            double mini_b = range_a + h * (i + 1);
            double mini_integration = integration(function, mini_a, mini_b);
            res += mini_integration;
        }
    } while (epsilon <= abs(res_old - res) && max_times > times);
    cout << "redouble_times: " << times << endl;
    return res;
}

void display_ans(const double &low_limit, const double &up_limit, const double &res)
{
    cout << fixed;
    cout << "low_limit: " << low_limit << endl;
    cout << "up_limit: " << up_limit << endl;
    cout << "integration_result: " << res << endl;
}

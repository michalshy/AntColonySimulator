export module Utils;
import <random>;

export float RandomFloat(int min, int max)
{
    const int range_from = min;
    const int range_to = max;
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(range_from, range_to);

    return distr(generator);
}

export float DegreesToRadians(float angle)
{
	float angleRADS = (3.1415926536 / 180) * (angle);
	return angleRADS;
}


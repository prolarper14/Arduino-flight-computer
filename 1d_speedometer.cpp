#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
    const double value = 15.0;
    double initial_estimate = 12.0;
    const double initial_measurement = 17.0;
    const double measurement_error = std::abs(initial_measurement - value);
    const std::vector<double> measurements{
        13.0, 14.0, 15.0, 16.0, 17.0, 18.0,
        19.0, 20.0, 21.0, 22.0, 23.0, 24.0
    };
    const double initial_error_estimate = std::abs(initial_estimate - value);
    double error_estimate = initial_error_estimate;

    std::cout << std::setprecision(15);

    for (const double measurement : measurements) {
        const double kalman_gain =
            error_estimate / (error_estimate + measurement_error);
        const double updated_estimate =
            initial_estimate + kalman_gain * (measurement - initial_estimate);

        error_estimate = (1.0 - kalman_gain) * error_estimate;

        std::cout << "Measurement: " << measurement
                  << ", Updated Estimate: " << updated_estimate
                  << ", Error Estimate: " << error_estimate << '\n';

        initial_estimate = updated_estimate;
    }

    return 0;
}

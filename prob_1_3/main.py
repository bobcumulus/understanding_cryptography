"""
1.3. We consider the long-term security of the Advanced Encryption Standard
(AES) with a key length of 128-bit with respect to exhaustive key-search attacks.
AES is perhaps the most widely used symmetric cipher at this time.
1. Assume that an attacker has a special purpose application specific integrated circuit (ASIC) which checks 5 · 108 keys per
second, and she has a budget of $1
million. One ASIC costs $50, and we assume 100% overhead for integrating
the ASIC (manufacturing the printed circuit boards, power supply, cooling, etc.).
How many ASICs can we run in parallel with the given budget? How long does
an average key search take? Relate this time to the age of the Universe, which is
about 10^10 years.

2. We try now to take advances in computer technology into account. Predicting
the future tends to be tricky but the estimate usually applied is Moore’s Law,
which states that the computer power doubles every 18 months while the costs
of integrated circuits stay constant. How many years do we have to wait until a
key-search machine can be built for breaking AES with 128 bit with an average
search time of 24 hours? Again, assume a budget of $1 million (do not take
inflation into account).
"""

from math import log2

def calculate_current_capabilities(budget, cost_per_asic, asic_rate, key_space):
    total_cost_per_asic = 2 * cost_per_asic  # Including 100% overhead
    num_asics = budget // total_cost_per_asic
    total_keys_per_second = num_asics * asic_rate
    average_search_time_seconds = (key_space / 2) / total_keys_per_second
    average_search_time_years = average_search_time_seconds / (60 * 60 * 24 * 365)
    return num_asics, average_search_time_years

def estimate_years_until_24h_break(average_search_time_years, target_time_years):
    n_periods = log2(average_search_time_years / target_time_years)
    years_until_feasible = n_periods * 1.5
    return years_until_feasible

def main():
    # Constants
    budget = 1_000_000
    cost_per_asic = 50
    asic_rate = 5 * 10**8  # Keys per second
    key_space = 2**128
    target_time_years = 1 / 365  # 24 hours in years

    # Part 1: Calculate current capabilities
    num_asics, average_search_time_years = calculate_current_capabilities(budget, cost_per_asic, asic_rate, key_space)
    print(f"Number of ASICs running in parallel: {num_asics}")
    print(f"Average key search time (years): {average_search_time_years:e}")

    # Part 2: Estimate years until a 24-hour break is feasible
    years_until_feasible = estimate_years_until_24h_break(average_search_time_years, target_time_years)
    print(f"Years until a 24-hour break is feasible: {years_until_feasible:.2f}")

if __name__ == "__main__":
    main()

#include "parallel_letter_frequency.h"

#include <string>
#include <algorithm>
#include <execution>

namespace parallel_letter_frequency {
	std::map<char, int> frequency(std::vector<std::string_view> texts)
	{
		std::map<char, int> retval;

		// non parallel implementation
		std::for_each(
			std::execution::par,
			texts.begin(), 
			texts.end(), 
			[&retval](std::string_view text)
			{
				for (char character : text)
				{
					if (std::isalpha(character))
					{
						char lower = std::tolower(character);
						retval[lower]++;
					}
				}
			}
		);
		return retval;
	}
}

#include "parallel_letter_frequency.h"

#include <string>

namespace parallel_letter_frequency {
	std::map<char, int> frequency(std::vector<std::string_view> texts)
	{
		std::map<char, int> retval;

		// non parallel implementation
		for(auto text : texts)
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

		return retval;
	}
}

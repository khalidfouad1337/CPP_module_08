/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:50:23 by khalid            #+#    #+#             */
/*   Updated: 2025/02/28 01:50:24 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
private:
    unsigned int maxSize;
    std::vector<int> numbers;

public:
    Span(unsigned int N) : maxSize(N) {}

    void addNumber(int num) {
        if (numbers.size() >= maxSize)
            throw std::runtime_error("Span is full! Cannot add more numbers.");
        numbers.push_back(num);
    }

    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end) {
        if (numbers.size() + std::distance(begin, end) > maxSize)
            throw std::runtime_error("Not enough space to add all numbers.");
        numbers.insert(numbers.end(), begin, end);
    }

    int shortestSpan() {
        if (numbers.size() < 2)
            throw std::runtime_error("Not enough numbers to calculate span.");
        
        std::vector<int> sorted = numbers;
        std::sort(sorted.begin(), sorted.end());

        int minSpan = sorted[1] - sorted[0];
        for (size_t i = 1; i < sorted.size() - 1; i++) {
            minSpan = std::min(minSpan, sorted[i + 1] - sorted[i]);
        }
        return minSpan;
    }

    int longestSpan() {
        if (numbers.size() < 2)
            throw std::runtime_error("Not enough numbers to calculate span.");
        
        return *std::max_element(numbers.begin(), numbers.end()) - 
               *std::min_element(numbers.begin(), numbers.end());
    }
};

#endif

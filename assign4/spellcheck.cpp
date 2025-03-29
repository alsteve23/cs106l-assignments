#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(const std::string& source) {
  //saves a vector of iterators of the whitespace characters
  auto vec=find_all(source.begin(), source.end(), isspace);
  vec.insert(vec.begin(),source.begin());
  vec.push_back(source.end());
  std::set<Token>tokens;
  //creates Tokens using th iterators whitespaces as limits.
   std::transform(
    vec.begin(),
    vec.end()-1,
    vec.begin()+1,
    std::inserter(tokens,tokens.end()),
    [&source](auto begin, auto end){return Token(source,begin,end);});
    //removes empty tokens
    std::erase_if(tokens,[](auto& token){return token.content.empty();});
    return Corpus(tokens);
}
std::set<Mispelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  namespace rv = std::ranges::views;
  auto filtered_tokens = source | rv::filter([&dictionary](const Token &token){ 
  return !dictionary.contains(token.content); 
  });

  std::set<Mispelling> result;

  auto misspelling_view = filtered_tokens | rv::transform([&dictionary](const Token &token){
    auto suggestions_view = dictionary | rv::filter([&token](const std::string &word){ 
      return levenshtein(token.content, word) == 1; 
    });
    
    std::set<std::string> suggestions(suggestions_view.begin(), suggestions_view.end());
    return Mispelling{token, suggestions};
  });
  auto empty_suggestions = misspelling_view | rv::filter([](const Mispelling &mispelling){ 
    return !mispelling.suggestions.empty(); 
  });
  return std::set<Mispelling>(empty_suggestions.begin(), empty_suggestions.end());
};


/* Helper methods */

#include "utils.cpp"
#!/usr/bin/python3
""" this module counts mentions of a given keyword from popular posts. """
import requests


def count_words(subreddit, word_list, hot_list=[], after='null'):
    """ returns hot posts from a given subreddit. """

    url = "https://www.reddit.com/r/" + subreddit + "/hot.json"
    credentials = {'User-Agent': "hbtncount (by /u/ArtisanGray)"}
    parameters = {"limit": "100", "after": after}
    response = requests.get(url, headers=credentials, params=parameters,
                            allow_redirects=False)
    if response.status_code != 200:
        return None

    hot_list_of_dicts = response.json().get("data").get("children")
    after = response.json().get("data").get("after")

    hot_list.extend([reddit.get("data").get("title") for
                     reddit in hot_list_of_dicts])

    if after is None:
        to_print_dict = {x: 0 for x in word_list}
        for word in word_list:

            count = 0
            for title in hot_list:
                split_title = title.split()
                new_split = [element.lower() for element in split_title]
                count = count + new_split.count(word.lower())

            if count != 0:
                to_print_dict[word] = to_print_dict[word] + count

        for elem in sorted(to_print_dict.items(), key=lambda x: (-x[1], x[0])):
            if elem[1] != 0:
                print("{}: {}".format(elem[0], elem[1]))
    else:
        return count_words(subreddit, word_list, hot_list, after)

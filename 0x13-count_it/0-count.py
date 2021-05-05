#!/usr/bin/python3
''' Word count module '''
import requests


def count_words(subreddit, word_list, count_dict={}, after=''):
    ''' Queries the reddit API for hot articles '''
    r = "https://www.reddit.com/r/{}/hot/.json".format(subreddit)
    u_a = {'User-agent': 'User Agent 1.0'}

    if len(count_dict) == 0:
        data = requests.get(r + '?limit=1', headers=u_a, allow_redirects=False)
        if data.status_code != 200:
            # print(data.status_code)
            print('')
            return ''
        jsn = data.json().get('data')
        if jsn is None or jsn.get('children') is None:
            return None
        tmp = jsn.get('children')[0].get('data').get('title')
        aft = jsn.get('after')
        tmp2 = [tmp]
        for word in word_list:
            count_dict.update({word: word_count(word, tmp2)})
        count_dict.update(count_words(subreddit, word_list, count_dict, aft))
        return count_dict
    else:
        data = requests.get(r + '?after={}'.format(after),
                            headers=u_a, allow_redirects=False)
        if data.status_code != 200:
            # print(data.status_code)
            return {}
        jsn = data.json().get('data')
        if jsn is None or jsn.get('children') is None:
            return count_dict
        hot_list = []
        for item in jsn.get('children'):
            hot_list.append(item.get('data').get('title'))
        # print(hot_list)
        aft = jsn.get('after')
        for word in word_list:
            count_dict.update({word: count_dict.get(word, 0) +
                               word_count(word, hot_list)})
        # print(count_dict)
        count_dict.update(count_words(subreddit, word_list, count_dict, aft))
        return count_dict


def word_count(word, title_list):
    ''' Counts the occurences of a word in a list of titles '''
    s = 0
    for title in title_list:
        tmp = title.lower().split(' ')
        s += tmp.count(word)
    return (s)

#!/usr/bin/python3
''' Word count module '''
import requests


def count_words(subreddit, word_list):
    ''' Queries the reddit API for hot articles '''
    res = recurse(subreddit, word_list)
    if res is None:
        print('')
    else:
        print_res(res)


def recurse(subreddit, word_list, count_dict={}, after='', multi={}):
    ''' Recursive aspect of function '''
    r = "https://www.reddit.com/r/{}/hot/.json".format(subreddit)
    u_a = {'User-agent': 'User Agent 1.0'}

    if len(count_dict) == 0:
        try:
            data = requests.get(r + '?limit=1',
                                headers=u_a, allow_redirects=False)
        except Exception as e:
            print(e)
            return None
        if data.status_code != 200:
            return None
        jsn = data.json().get('data')
        if jsn is None or jsn.get('children') is None:
            return None
        tmp = jsn.get('children')[0].get('data').get('title')
        aft = jsn.get('after')
        tmp2 = [tmp]
        word_list_tmp = [word.lower() for word in word_list]
        for word in word_list:
            if word_list_tmp.count(word.lower()) > 1:
                multi.update({word.lower(): word_list_tmp.count(word.lower())})
        word_list = list(set(word_list_tmp))
        for word in word_list:
            count_dict.update({word: word_count(word, tmp2, multi)})
        count_dict.update(recurse(subreddit, word_list,
                                  count_dict, aft, multi))
        return count_dict
    else:
        data = requests.get(r + '?after={}'.format(after),
                            headers=u_a, allow_redirects=False)
        if data.status_code != 200:
            return count_dict
        jsn = data.json().get('data')
        if jsn is None or jsn.get('children') is None:
            return count_dict
        hot_list = []
        for item in jsn.get('children'):
            hot_list.append(item.get('data').get('title'))
        aft = jsn.get('after')
        for word in word_list:
            count_dict.update({word: count_dict.get(word, 0) +
                               word_count(word, hot_list, multi)})
        # print(count_dict)
        if (aft is None):
            return count_dict
        else:
            count_dict.update(recurse(subreddit,
                                      word_list, count_dict, aft, multi))
            return count_dict


def word_count(word, title_list, multi):
    ''' Counts the occurences of a word in a list of titles '''
    s = 0
    for title in title_list:
        tmp = title.lower().split(' ')
        s += tmp.count(word) * multi.get(word, 1)
    return (s)


def print_res(res_d):
    ''' Prints a dictionary in descending order '''
    sorted_keys = sorted(res_d, key = lambda x: (-res_d[x], x))
    for key in sorted_keys:
        if res_d.get(key, 0) > 0:
            print(key + ':', res_d.get(key))

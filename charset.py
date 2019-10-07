#%%

# strinput = input()
# strinput = 'a:1@'
strinput = 'a:1,b:2@a:1'

if strinput == '':
    print('')
else:
    # avaliable, unavaliable = input().split('@')
    # avaliable, unavaliable = 'a:3,b:5,c:2@a:1,b:2'.split('@')
    # avaliable, unavaliable = 'a:3,b:5,c:2@a:3,b:2'.split('@')
    # avaliable, unavaliable = 'a:3,b:5,c:2@'.split('@')
    avaliable, unavaliable = strinput.split('@')


    #%%
    try:
        key_values_a = avaliable.split(',')
    except:
        pass

    #%%
    ava_charset = {}
    ava_list = []
    for kv in key_values_a:
        key, value = kv.split(':')
        value = eval(value)
        ava_charset[key] = value
        ava_list.append(key)

    #%%
    try:
        key_values_u = unavaliable.split(',')
    except:
        pass

    #%%
    uava_charset = {}
    for kv in key_values_u:
        if len(kv) >= 1:
            key, value = kv.split(':')
            value = eval(value)
            uava_charset[key] = value

    #%%
    for uchar in uava_charset.keys():
        ava_charset[uchar] -= uava_charset[uchar]

    final_charset = {}
    for key in ava_charset.keys():
        if ava_charset[key] != 0:
            final_charset[key] = ava_charset[key]
        else:
            ava_list.remove(key)

    #%%
    strava = ''
    for key in ava_list:
        strava += '{}:{},'.format(key, final_charset[key])
    strava = strava[:-1]

    #%%
    print(strava)

#%%

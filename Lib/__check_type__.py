func = None

def check(_object, name, types):
    for _type in types:
        if _type is None:
            _type = type(None)

        if _type is func and callable(_object):
            return

        if isinstance(_object, _type):
            return

    msg = f"Invalid value type. The '{name}' parameter must be an instance of one of the following types:"
    for _type in types:
        msg += f"\n{_type}"

    raise TypeError(msg)

func = type(check)

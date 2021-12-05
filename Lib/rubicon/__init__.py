try:
    # If we're on iOS, we won't have pkg-resources; but then,
    # we won't need to register the namespace package, either.
    # Ignore the error if it occurs.
    __import__("pkg_resources").declare_namespace(__name__)
except ImportError:
    pass

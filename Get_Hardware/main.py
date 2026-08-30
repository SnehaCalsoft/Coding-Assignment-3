import platform

from .linux_host import LinuxHost
from .windows_host import WindowsHost


def main():

    os_type = platform.system()

    if os_type == "Linux":
        host = LinuxHost()

    elif os_type == "Windows":
        host = WindowsHost()

    else:
        raise RuntimeError("Unsupported operating system")

    host.get_hardware_info()
    host.display_hardware_info()


if __name__ == "__main__":
    main()
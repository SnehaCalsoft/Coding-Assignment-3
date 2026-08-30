from .host_info import HostInfo
import subprocess
import socket


class WindowsHost(HostInfo):

    def get_hardware_info(self):

        # Hostname
        self.hostname = socket.gethostname()

        # IP address
        self.ip = socket.gethostbyname(self.hostname)

        # CPU
        cpu_output = subprocess.check_output(
            [
                "powershell",
                "-Command",
                "(Get-CimInstance Win32_Processor).Name"
            ],
            text=True
        ).strip()

        self.cpu = cpu_output

        # Memory
        memory_output = subprocess.check_output(
            [
                "powershell",
                "-Command",
                "(Get-CimInstance Win32_ComputerSystem).TotalPhysicalMemory"
            ],
            text=True
        ).strip()

        memory_bytes = int(memory_output)

        memory_gb = memory_bytes / (1024 ** 3)

        self.memory = f"{memory_gb:.2f} GB"

        # Disk
        disk_output = subprocess.check_output(
            [
                "powershell",
                "-Command",
                "(Get-CimInstance Win32_LogicalDisk -Filter \"DeviceID='C:'\").Size"
            ],
            text=True
        ).strip()

        disk_bytes = int(disk_output)

        disk_gb = disk_bytes / (1024 ** 3)

        self.disk_size = f"{disk_gb:.2f} GB"
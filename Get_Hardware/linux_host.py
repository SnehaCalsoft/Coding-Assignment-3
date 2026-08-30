from .host_info import HostInfo
import subprocess
import socket


class LinuxHost(HostInfo):

    def get_hardware_info(self):

        # Hostname
        self.hostname = socket.gethostname()

        # IP address
        self.ip = socket.gethostbyname(self.hostname)

        # CPU
        cpu_output = subprocess.check_output(
            ["nproc"],
            text=True
        ).strip()

        self.cpu = cpu_output + " cores"

        # Memory
        memory_output = subprocess.check_output(
            ["free", "-h"],
            text=True
        )

        for line in memory_output.splitlines():
            if line.startswith("Mem:"):
                parts = line.split()
                self.memory = parts[1]
                break

        # Disk
        disk_output = subprocess.check_output(
            ["df", "-h", "/"],
            text=True
        )

        lines = disk_output.splitlines()

        if len(lines) > 1:
            parts = lines[1].split()
            self.disk_size = parts[1]
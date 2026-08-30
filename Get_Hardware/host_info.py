from abc import ABC, abstractmethod
import json


class HostInfo(ABC):

    def __init__(self):
        self.hostname = ""
        self.memory = ""
        self.cpu = ""
        self.ip = ""
        self.disk_size = ""

    @abstractmethod
    def get_hardware_info(self):
        pass

    def display_hardware_info(self):
        hardware_info = {
            "hostname": self.hostname,
            "memory": self.memory,
            "cpu": self.cpu,
            "ip": self.ip,
            "disk_size": self.disk_size
        }

        print(json.dumps(hardware_info, indent=4))
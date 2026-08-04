_This project has been created as part
of the 42 curriculum by zleullie._

# Born2BeRoot
An introduction to the wonderful world of virtualization (and systems administration).

## Description (overview)
This project is an introduction to systems administrations, and also to virtual machines. We have to setup partitioning in a specific way, setup policies and users, install and configure services, and manage recurring jobs.

## Project Description
During the development of this project, numerous decisions were taken:

- Debian was picked instead of Rocky simply because I have more experience with Debian-based distributions. Debian has essentially no advantages or disadvantages compared to Rocky Linux, they are simply different distributions. Debian uses apt and the .deb format for packages, Rocky mimics RHEL and uses DNF and the .rpm format for packages.
- AppArmor was used because it is the default for Debian. It is also simpler to use.
- UFW was used because of it's uncomplicated nature. It's even in UFW's name: uncomplicated firewall. It's also the default for Debian and what the subject requests. Firewalld uses a zone based system that is more complex.
- VirtualBox is Oracle's virtual machine solution. UTM is a virtualization software made specifically for Apple devices running iOS or macOS. UTM is based on QEMU, while VirtualBox uses its own proprietary kernel module `vboxdrv`.

Partitioning was made with similar sizes and layout to the subject, due to the requirements. The partition was encrypted with LUKS. Ext4 was used as the filesystem because of its stability and performance.

Sudo is setup to allow users in the `sudo` group to run commands as root.

The password policies are setup in `/etc/pam.d/common-password`, with `pam_pwquality.so`, with password age policy setup in `/etc/login.defs`.

Wordpress was installed as a Debian package, with the contents in `/var/wordpress/` for mutability, and configuration files in `/etc/wordpress`.

The monitoring script is placed in `/usr/local/bin/monitoring.sh` and is run periodically and on startup by a systemd unit file and timer. I have chosen systemd instead of CRON because it would make my life easier to run the script on startup.

For my bonus service, I have installed `cloudflared`. `cloudflared` offers a high performance, low latency tunnel to the internet over Cloudflare's edge network, allowing the internet to access a service on my machine securely, without fiddling with network configurations or HTTPS certificates. You can access the WordPress website from [b2br.zoe.dev.br](https://b2br.zoe.dev.br) when the VM is on. 

## Instructions
It is **strongly** recommended that you use the Born2BeRoot.tar archive instead of the raw disk image, as it already has EFI variables and all necessary port forwarding configurations set up.

### Steps for archive (.tar)
1. Download & extract [Born2BeRoot.tar](https://drive.google.com/file/d/1zyRd2zKWv2jmjAcbvYlVkK6XiNXECWSE/view?usp=sharing)
2. Add the VM to VirtualBox
3. Launch the VM

### Steps for the disk image (.vdi)
1. Download & extract [Born2BeRoot.tar](https://drive.google.com/file/d/1zyRd2zKWv2jmjAcbvYlVkK6XiNXECWSE/view?usp=sharing)
2. Create a new VM in VirtualBox, and import the disk image into it
3. Enable EFI if not enabled already
4. Enable port forwarding for ports 4242 (to port 42424) and 80 (to 8080).
5. Run VM.
_Note: it may fail due to missing NVRAM variables. In which case, either copy the .nvram file from the archive, or get a Debian recovery image and reinstall the bootloader._

## Passwords

| Main user (zleullie) | Root user (root)   | Disk encryption key            |
|----------------------|--------------------|--------------------------------|
| ILoveRaspberries2!   | ILoveBlueberries2! | ChattingAbroad4RaspberryDrone! |

## Resources
Resources used were mostly these, with my own knowledge and experience:

- [Debian Documentation](https://www.debian.org/doc/)
- [ArchWiki](https://wiki.archlinux.org/title/Main_page)

## AI Disclaimer
AI was used to assist in the writing of the `monitoring.sh` script, by showing me snippets that I assembled into the final part. AI was also used when searching the internet with Google, as part of the AI overview tab.


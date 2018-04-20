# Ensure VirtualBox is used as default provider
ENV['VAGRANT_DEFAULT_PROVIDER'] = 'virtualbox'

Vagrant.configure(2) do |config|
  config.vm.box = "generic/fedora27"
  config.vm.hostname = "llvm-toolchain"

  config.vm.synced_folder "vm-files/", "/vagrant"

  config.vm.provider "virtualbox" do |vb|
    vb.name = "devconf_2018"
    vb.gui = true
    vb.memory = "8192"
    vb.cpus = 4
    # vb.customize ["modifyvm", :id, "--vram", "96"]
    # vb.customize ["modifyvm", :id, "--videocap", "on"]
    # vb.customize ["modifyvm", :id, "--videocapfile", "screen.webm"]
    # vb.customize ["modifyvm", :id, "--videocapres", "1920x1080"]
    # vb.customize ["modifyvm", :id, "--videocaprate", "1080"]
  end

  # Provision (update, install, configure)
  config.vm.provision :shell, path: "bootstrap.sh"

end

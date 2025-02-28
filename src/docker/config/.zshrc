# Sample Zsh configuration file optimized for development and containers.
#
# Roberto Masocco <robmasocco@gmail.com>
# Alessandro Tenaglia <alessandro.tenaglia42@gmail.com>
#
# January 27, 2022

# If you come from bash you might have to change your $PATH.
# export PATH=$HOME/bin:/usr/local/bin:$PATH

# Uncomment the following line to use case-sensitive completion.
CASE_SENSITIVE="true"

# This is where command history will be saved
if [[ -z "$BOARD" ]]; then
  # Not in a container
  export HISTFILE=~/.zsh_history
else
  # In a container: save it on the host
  export HISTFILE=~/zsh_history/.zsh_history
  if [[ ! -d ~/zsh_history ]]; then
    mkdir -p ~/zsh_history
  fi
fi
touch $HISTFILE

# NuttX toolchain location (for development containers)
if ! echo "$BOARD" | grep -q 'up' && ! echo "$BOARD" | grep -q 'nx'; then
  export PATH=/opt/gcc-arm-none-eabi-9-2020-q2-update/bin:$PATH
fi

# Gradle location
export PATH=/opt/gradle/gradle-$GRADLE_VERSION/bin:$PATH

# If this is a login shell just set the prompt, basic stuff and get out
if [[ "$TERM" == "linux" ]]; then
  export LANG=en_US.UTF-8
  if [[ -n $SSH_CONNECTION ]]; then
    export EDITOR='vim'
  else
    export EDITOR='nano'
  fi
  source ~/.aliases.sh
  source ~/.ros2_cmds.sh
  if [[ -f ~/.stanis_aliases.sh ]]; then
    source ~/.stanis_aliases.sh
  fi
  PROMPT='%B%F{red}%n@%M%f %F{yellow}%~%f %F{white}(%?%) $%f%b '
  return
fi

# Path to your oh-my-zsh installation.
export ZSH="$HOME/.oh-my-zsh"

# Set name of the theme to load --- if set to "random", it will
# load a random theme each time oh-my-zsh is loaded, in which case,
# to know which specific one was loaded, run: echo $RANDOM_THEME
# See https://github.com/ohmyzsh/ohmyzsh/wiki/Themes
ZSH_THEME="powerlevel10k/powerlevel10k"

# Set list of themes to pick from when loading at random
# Setting this variable when ZSH_THEME=random will cause zsh to load
# a theme from this variable instead of looking in $ZSH/themes/
# If set to an empty array, this variable will have no effect.
# ZSH_THEME_RANDOM_CANDIDATES=( "robbyrussell" "agnoster" )

# Uncomment the following line to use hyphen-insensitive completion.
# Case-sensitive completion must be off. _ and - will be interchangeable.
# HYPHEN_INSENSITIVE="true"

# Uncomment one of the following lines to change the auto-update behavior
# zstyle ':omz:update' mode disabled  # disable automatic updates
# zstyle ':omz:update' mode auto      # update automatically without asking
zstyle ':omz:update' mode disabled  # just remind me to update when it's time

# Uncomment the following line to change how often to auto-update (in days).
# zstyle ':omz:update' frequency 13

# Uncomment the following line if pasting URLs and other text is messed up.
# DISABLE_MAGIC_FUNCTIONS="true"

# Uncomment the following line to disable colors in ls.
# DISABLE_LS_COLORS="true"

# Uncomment the following line to disable auto-setting terminal title.
# DISABLE_AUTO_TITLE="true"

# Uncomment the following line to enable command auto-correction.
# ENABLE_CORRECTION="true"

# Uncomment the following line to display red dots whilst waiting for completion.
# You can also set it to another string to have that shown instead of the default red dots.
# e.g. COMPLETION_WAITING_DOTS="%F{yellow}waiting...%f"
# Caution: this setting can cause issues with multiline prompts in zsh < 5.7.1 (see #5765)
# COMPLETION_WAITING_DOTS="true"

# Uncomment the following line if you want to disable marking untracked files
# under VCS as dirty. This makes repository status check for large repositories
# much, much faster.
# DISABLE_UNTRACKED_FILES_DIRTY="true"

# Uncomment the following line if you want to change the command execution time
# stamp shown in the history command output.
# You can set one of the optional three formats:
# "mm/dd/yyyy"|"dd.mm.yyyy"|"yyyy-mm-dd"
# or set a custom format using the strftime function format specifications,
# see 'man strftime' for details.
# HIST_STAMPS="mm/dd/yyyy"

# Would you like to use another custom folder than $ZSH/custom?
# ZSH_CUSTOM=/path/to/new-custom-folder

# Which plugins would you like to load?
# Standard plugins can be found in $ZSH/plugins/
# Custom plugins may be added to $ZSH_CUSTOM/plugins/
# Example format: plugins=(rails git textmate ruby lighthouse)
# Add wisely, as too many plugins slow down shell startup.
plugins=(git git-extras git-flow colorize command-not-found common-aliases zsh-syntax-highlighting zsh-autosuggestions sudo colored-man-pages)

source $ZSH/oh-my-zsh.sh

# User configuration

# export MANPATH="/usr/local/man:$MANPATH"

# You may need to manually set your language environment
export LANG=en_US.UTF-8

# Preferred editor for local and remote sessions
if [[ -n $SSH_CONNECTION ]]; then
  export EDITOR='vim'
else
  export EDITOR='nano'
fi

# Compilation flags
# export ARCHFLAGS="-arch x86_64"

# Set personal aliases, overriding those provided by oh-my-zsh libs,
# plugins, and themes. Aliases can be placed here, though oh-my-zsh
# users are encouraged to define aliases within the ZSH_CUSTOM folder.
# For a full list of active aliases, run `alias`.
#
# Example aliases
# alias zshconfig="mate ~/.zshrc"
# alias ohmyzsh="mate ~/.oh-my-zsh"
unalias rm
[[ ! -f ~/.aliases.sh ]] || source $HOME/.aliases.sh
[[ ! -f ~/.ros2_cmds.sh ]] || source $HOME/.ros2_cmds.sh
[[ ! -f ~/.stanis_aliases.sh ]] || source ~/.stanis_aliases.sh

# To customize prompt, run `p10k configure` or edit ~/.p10k.zsh.
[[ ! -f ~/.p10k.zsh ]] || source ~/.p10k.zsh

# stanis project aliases
if [[ -f ~/workspace/stanis/config/.gcs_aliases.sh ]]; then
    source ~/workspace/stanis/config/.gcs_aliases.sh
fi

# Routines to open shells in base containers
if echo "$USER" | grep -q 'up'; then
  function attach-base {
    cd ~/stanis
    docker-compose exec stanis-base zsh
  }
elif echo "$USER" | grep -q 'nx'; then
  function attach-base {
    cd ~/stanis
    docker-compose exec stanis-base-nx zsh
  }
fi
source /opt/ros/melodic/setup.zsh

# functions
matlab() {
    #do things with parameters like $1 such as
    "/home/ros/MATLAB/R"$1"/bin/matlab"
}


# pyenv
#export PATH="$HOME/.pyenv/bin:$PATH"
#eval "$(pyenv init -)"
#eval "$(pyenv virtualenv-init -)"
source /opt/ros/melodic/setup.zsh
export LD_LIBRARY_PATH=/opt/ros/melodic/lib:/usr/local/nvidia/lib:/usr/local/nvidia/lib64:/usr/lib:/usr/local/lib:/usr/lib:/usr/local/lib:/usr/lib:/usr/local/lib:/usr/lib:/usr/local/lib:/usr/lib:/usr/local/lib
source /opt/ros/melodic/setup.zsh
export LD_LIBRARY_PATH=/opt/ros/melodic/lib:/usr/local/nvidia/lib:/usr/local/nvidia/lib64:/usr/lib:/usr/local/lib:/usr/lib:/usr/local/lib:/usr/lib:/usr/local/lib:/usr/lib:/usr/local/lib:/usr/lib:/usr/local/lib:/usr/lib:/usr/local/lib
source /opt/ros/melodic/setup.zsh
export LD_LIBRARY_PATH=/opt/ros/melodic/lib:/usr/local/nvidia/lib:/usr/local/nvidia/lib64:/usr/lib:/usr/local/lib:/usr/lib:/usr/local/lib:/usr/lib:/usr/local/lib:/usr/lib:/usr/local/lib:/usr/lib:/usr/local/lib:/usr/lib:/usr/local/lib:/usr/lib:/usr/local/lib
source /opt/ros/melodic/setup.zsh
export LD_LIBRARY_PATH=/opt/ros/melodic/lib:/usr/local/nvidia/lib:/usr/local/nvidia/lib64:/usr/lib:/usr/local/lib:/usr/lib:/usr/local/lib:/usr/lib:/usr/local/lib:/usr/lib:/usr/local/lib:/usr/lib:/usr/local/lib:/usr/lib:/usr/local/lib:/usr/lib:/usr/local/lib:/usr/lib:/usr/local/lib
